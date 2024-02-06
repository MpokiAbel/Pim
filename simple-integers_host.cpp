/*
  Simple example for BFVrns (integer arithmetic)
 */

#include "openfhe.h"
#include "dpu_host_helpers.h"

using namespace lbcrypto;

int main()
{
  // Sample Program: Step 1: Set CryptoContext
  CCParams<CryptoContextBFVRNS> parameters;
  parameters.SetPlaintextModulus(65537);
  parameters.SetMultiplicativeDepth(2);

  CryptoContext<DCRTPoly> cryptoContext = GenCryptoContext(parameters);
  // Enable features that you wish to use
  cryptoContext->Enable(PKE);
  cryptoContext->Enable(KEYSWITCH);
  cryptoContext->Enable(LEVELEDSHE);

  // Sample Program: Step 2: Key Generation

  // Initialize Public Key Containers
  KeyPair<DCRTPoly> keyPair;

  // Generate a public/private key pair
  keyPair = cryptoContext->KeyGen();

  // Generate the relinearization key
  cryptoContext->EvalMultKeyGen(keyPair.secretKey);

  // Generate the rotation evaluation keys
  cryptoContext->EvalRotateKeyGen(keyPair.secretKey, {1, 2, -1, -2});

  // Sample Program: Step 3: Encryption

  // First plaintext vector is encoded
  std::vector<int64_t> vectorOfInts1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Plaintext plaintext1 = cryptoContext->MakePackedPlaintext(vectorOfInts1);
  // Second plaintext vector is encoded
  std::vector<int64_t> vectorOfInts2 = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Plaintext plaintext2 = cryptoContext->MakePackedPlaintext(vectorOfInts2);
  // Third plaintext vector is encoded
  std::vector<int64_t> vectorOfInts3 = {1, 2, 5, 2, 5, 6, 7, 8, 9, 10, 11, 12};
  Plaintext plaintext3 = cryptoContext->MakePackedPlaintext(vectorOfInts3);

  // The encoded vectors are encrypted
  auto ciphertext1 = cryptoContext->Encrypt(keyPair.publicKey, plaintext1);
  auto ciphertext2 = cryptoContext->Encrypt(keyPair.publicKey, plaintext2);
  auto ciphertext3 = cryptoContext->Encrypt(keyPair.publicKey, plaintext3);

  // Sample Program: Step 4: Evaluation
  // ciphertext1->GetElements()
  std::vector<long> data{0x0706050403020100l};
  run_on_dpu(data);

  // Homomorphic additions
  auto ciphertextAdd12 = cryptoContext->EvalAdd(ciphertext1, ciphertext2);
  auto ciphertextAddResult = cryptoContext->EvalAdd(ciphertextAdd12, ciphertext3);

  // Homomorphic multiplications
  auto ciphertextMul12 = cryptoContext->EvalMult(ciphertext1, ciphertext2);
  auto ciphertextMultResult = cryptoContext->EvalMult(ciphertextMul12, ciphertext3);

  // Homomorphic rotations
  auto ciphertextRot1 = cryptoContext->EvalRotate(ciphertext1, 1);
  auto ciphertextRot2 = cryptoContext->EvalRotate(ciphertext1, 2);
  auto ciphertextRot3 = cryptoContext->EvalRotate(ciphertext1, -1);
  auto ciphertextRot4 = cryptoContext->EvalRotate(ciphertext1, -2);

  // Sample Program: Step 5: Decryption

  // Decrypt the result of additions
  Plaintext plaintextAddResult;
  cryptoContext->Decrypt(keyPair.secretKey, ciphertextAddResult, &plaintextAddResult);

  // Decrypt the result of multiplications
  Plaintext plaintextMultResult;
  cryptoContext->Decrypt(keyPair.secretKey, ciphertextMultResult, &plaintextMultResult);

  // Decrypt the result of rotations
  Plaintext plaintextRot1;
  cryptoContext->Decrypt(keyPair.secretKey, ciphertextRot1, &plaintextRot1);
  Plaintext plaintextRot2;
  cryptoContext->Decrypt(keyPair.secretKey, ciphertextRot2, &plaintextRot2);
  Plaintext plaintextRot3;
  cryptoContext->Decrypt(keyPair.secretKey, ciphertextRot3, &plaintextRot3);
  Plaintext plaintextRot4;
  cryptoContext->Decrypt(keyPair.secretKey, ciphertextRot4, &plaintextRot4);

  plaintextRot1->SetLength(vectorOfInts1.size());
  plaintextRot2->SetLength(vectorOfInts1.size());
  plaintextRot3->SetLength(vectorOfInts1.size());
  plaintextRot4->SetLength(vectorOfInts1.size());

  // std::cout << "Plaintext #1: " << plaintext1 << std::endl;
  // std::cout << "Plaintext #2: " << plaintext2 << std::endl;
  // std::cout << "Plaintext #3: " << plaintext3 << std::endl;

  // // Output results
  // std::cout << "\nResults of homomorphic computations" << std::endl;
  // std::cout << "#1 + #2 + #3: " << plaintextAddResult << std::endl;
  // std::cout << "#1 * #2 * #3: " << plaintextMultResult << std::endl;
  // std::cout << "Left rotation of #1 by 1: " << plaintextRot1 << std::endl;
  // std::cout << "Left rotation of #1 by 2: " << plaintextRot2 << std::endl;
  // std::cout << "Right rotation of #1 by 1: " << plaintextRot3 << std::endl;
  // std::cout << "Right rotation of #1 by 2: " << plaintextRot4 << std::endl;

  return 0;
}
