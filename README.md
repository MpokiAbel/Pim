# Project P4
This is the introduction of Project P4 (Practical Privacy Preserving Processing).

## In-Memory Processing on Encrypted Data

### Objective:
Evaluate the types of operations that can be done over encrypted data on UPMEM chips and that provide performance benefits over migrating the data to main memory.

The main idea is to evaluate the types of operations that can be done over encrypted data on UPMEM Chips and that provide performance benefits over migrating the data to main memory.

The operations include but not limited to:
1. Search/query
2. Filter
3. Summarize/aggregate/Count

### Steps:
We would like to compare the cost of several scenarios:
1. Implement the algorithm with UPMEM SDK and do the operation directly on PIM DRAM.
2. Copy data from PIM DRAM to main CPU; do the operation over encrypted data on CPU.
3. Copy data from PIM DRAM to main CPU and do the operation in SGX enclave (decrypting it in the enclave).
4. As baseline but insecure: copy data from PIM DRAM to main CPU, decrypt, and do the operation over plain data on CPU.

This would provide us with a good survey of the kind of algorithms we can (relatively easily) execute on PIM DRAM over encrypted data, for which we have performance benefits.

For more details on progress of the project click [here]() 
# Installation 
To run the programs you need to have the following
1. UPMEM TOOLCHAIN INSTALLED for further infomation see the [usermanual](https://sdk.upmem.com/stable/01_Install.html)  
2. For Homomophic Operations install the [OpenFHE library](https://github.com/openfheorg/openfhe-development)  

This project contains a CMAKE file that intergrates both the UPMEM TOOLCHAIN and the OPENFHE library. If specific features are desired feel free to modify the CMakeLists.txt.

As a side note it is importatnt to know that while the dpu programs need to be written in C, the host program for this projects have been written in C++ for easy intergration with the use of the OPENFHE library which is natively in C++. 

# To run the program:
mkdir -p build  
cd ./build  
cmake ..  
make  
./xxxx_host
