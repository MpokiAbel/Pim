# Introduction
This is project is about Garbled Circuits, and their integration with the UPMEM PIM

# Garbled Circuit
A cryptographic protocol that enable two mistrusting parties to evaluate a function without revealing their private input without presence of third trusted party. For better explanation of the protocol visit [here](https://en.wikipedia.org/wiki/Garbled_circuit). There quite a few libraries with GC implementations, here is a non-exhastive list:
- [TinyGarble](https://github.com/IntelLabs/TinyGarble2.0)

## Usecases for GC
- User Password Reuse Detection between companies. To be explained
- Generic screening service. To be explained

## Security Model
- `Semi-honest` model ensures that untended information is never revealed to the conter-parties provided that they follow the protocol. The original GC protocol falls under this model.
- `Malicious` model the advesary tries to go around the protocols it has variants which include:
          - `Cut and Choose` model make the circuit generator to create copies of the encrypted circuit and send to the evaluator and choose 60% of them and has to verify that all the circuit are legitimate implementation of the function f otherwise quits.  
          - `On bit Leaked`  model make both parties to play the role of the generator and the garbler

# Related Work
- [MAGE](https://www.usenix.org/conference/osdi21/presentation/kumar) is an execution engine or memory planner for Secure Computation (SC) that handles computations exceeding available memory. It was created based on the observation that SC schemes are inherently oblivious, meaning their memory access patterns are independent of the input data hence could be predicted/planned in advance. By predicting these patterns, MAGE creates an efficient memory management plan, allowing SC computations to run almost as fast as if there were unlimited physical memory, significantly outperforming traditional OS virtual memory system.
- [Piranha](https://www.usenix.org/system/files/sec22-watson.pdf) is a platform that accelerates secure multi-party computation (MPC) using GPUs, simplifying the process for developers without requiring GPU expertise. They achive this by having a three layered achitecture most importantly the Device layer which provides the GPUs abstraction and give access to the integer kernels .Their demonstration is based on three linear secret sharing protocols for secure NN training.
- [Faster Secure Computation through Automatic Parallelization](https://www.usenix.org/system/files/conference/usenixsecurity15/sec15-paper-buescher.pdf) provides a compiler which parallelise the FGP as well as CGP (by depocomposing it into smaller parallelizable circuits). Finaly they introduce the IPP scheme, which load balances the protocol between parties by switching the garbling and evauating roles.
- [GPU and CPU Parallelization of Honest-but-Curious Secure Two-Party Computation](https://shelat.khoury.northeastern.edu/dl/hmsg13-gpuyao.pdf)
- [GraphSC: Parallel Secure Computation Made Easy](https://www.ieee-security.org/TC/SP2015/papers-archived/6949a377.pdf)
- [Secure Multiparty Computation and Trusted Hardware: Examining Adoption Challenges and Opportunities](https://onlinelibrary.wiley.com/doi/epdf/10.1155/2019/1368905)
- [HAAC: A Hardware-Software Co-Design to Accelerate Garbled Circuits](https://arxiv.org/pdf/2211.13324)
- [Faster Maliciously Secure Two-Party Computation Using the GPU](https://eprint.iacr.org/2014/270.pdf)
