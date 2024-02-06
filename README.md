# UPMEM-PIM
This is the introduction of Project UPMEM-HOMOMOPHIC : In-Memory Processing on Encrypted Data

The main idea is Evaluate the types of operations that can be done over encrypted data on UPMEM chips and that provide performance benefits over migrating the data to main memory.

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


# List of Papers (References):

1.[A Case Study of Processing-in-Memory in off-the-Shelf Systems](https://www.usenix.org/system/files/atc21-nider.pdf)  
2.[Benchmarking a New Paradigm: An Experimental Analysis of a Real Processing-in-Memory Architecture](https://arxiv.org/pdf/2105.03814.pdf%C3%82%C2%A0%C3%82%C2%A0)  
3.[SoK: New Insights into Fully Homomorphic Encryption Libraries via Standardized Benchmarks](https://eprint.iacr.org/2022/425.pdf)  
4.[FHEmem: A Processing In-Memory Accelerator for Fully Homomorphic Encryption](https://arxiv.org/pdf/2311.16293.pdf)