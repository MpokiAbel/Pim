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
