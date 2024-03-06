# Introduction
This is the main documentation of the project "In-Memory Processing on Encrypted Data" which aims to run multiple operations on UPMEM PIM chips and evaluate the perfomance benefits it provides

# Tasks
The openFHE library is developed in a modular design and provides the Hardware Abstraction Layer (HAL) which main goal is to support multiple instantiations of the bottleneck polynomial
and RNS operations in this layers. The design provides multiple backends for intergers, modular vectors, NTT transformations and polynomials while using the same implementation.

My Plan is to have the comparison for Integers based on BGV and BFV, and Boolean arithmetic, comparisons, and aribtrary function evaluation based on DM and CGGI schemes. 
However, working with CKKS presents challenges since it operates on floating-point numbers, not yet supported by the UPMEM PIM hardware and native compiler. 
Emulated floating-point operations are notably slow and should be avoided.

As a starting point for the schemes highlighted (BGV and BFV), my main focus is on the following operations:
1. Addition
2. Multiplication
3. Rotation

With each operations there exists a varieties of how the operation is done, for example:
1.If the operation is between ciphertext and ciphertext or between ciphertext and plaintext
2.The implementation backend (Math Backend) used on the HAL layer. The available backend are as follows:
    (i) MATHBACKEND 2 Has an explicit max size of `BigInteger` default to 3000 bits. 
    (ii) MATHBACKEND 4 No Explicit max size of `BigInteger`, Size grows dynamically and is only constrained by memory 
    (iii) MATHBACKEND 6 Integration of `NTL` library with `OpenFHE`

# Progress
So far we have been able to do the following tasks.
 1. Integrating the Library with the PIM toolchain during compilation to enable smooth running of experiments.
    The user has to turn the flag RUN_ON_DPU to run the specific operation from the DPU.
 2. Implement a subset of operations for the intended operation to the DPU. At the moment i have incooperated the MATHBACKEND 4 which does not involve the NTT library. 

Tasks at hand:
- My current implementation have incoperated moving a single tower and perform the modular addition of these tower on the DPU against another after completion fetches another tower.
  To give more context, The operations involves polynomial arithmetics and involves bigIntergers and large modulus. For efficiency i am using the DCRTPoly representation which is different to Poly representation.
  In practice, this means that Poly uses a single large modulus q, while DCRTPoly uses multiple smaller moduli. Hence, Poly runs slower than DCRTPoly because DCRTPoly operations can be easier
  to fit into the native bitwidths of commodity processors. Therefore a tower would mean a single vector element of DCRTpoly.
  
- Therefore to minimize multiple calling to the dpu copy operation i am working on copying all DCRTpoly towers to the DPU memory. This would mean moving from the deeper layer(math)
  where the actual computations were done to lattice layer of openFHE where DCRTpoly is represented, this should not be an issue.

Minor Challenges:
- I have been running some experiments on the actual PIM server (I still have acess to the PIM server at LIG lab at Grenoble ) for the operation i have implemented, however I face some errors.
    (The error sometimes appears as Internal error, timeout or identity error ). Suprisingly i dont face this error while using the Simulator and my code runs well !!.
    The error appears when trying to run the DPU program mutliple times.

Additional Comments.

It could be interesting to see how operations such as bootstraping, scheme switching and key switching behave when run on PIM. According to some papers these operations are not computate-bound 
but rather memory-bound. And it makes alot of sense to look into these operations because practically users may involve performing multiple operations either (addition,multiplication or rotation) 
and in sequesnce to that bootstraping is essential to reduce noise.  

# Project
The project code and installation is avalable [here](https://github.com/MpokiAbel/UPMEM-OpenFHE)  


ToDo:
1. Make the memory management of the dpu efficient.
2. Make the host application know the maximum it can send to the DPU which is 64MB max. Hence would need to split the ciphertext equally for the vector additions. 
3. Performs an indepth evaluation of the addition operations - Get an idea from the benchmarking evaluations.
4. Evaluate the execution of multiplications and Rotations operation.
5. Deploy the operations to the DPU as well.
6. Trace the problem resulting from the DPU errors
7. Study the benchmarks avalable for performance measurements.
