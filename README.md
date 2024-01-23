# Pim
This is the introduction of Project UPMEM-HOMOMOPHIC.

The main idea is to run the Homomophic Operation on the UPMEM chips

# Installation 
To run the programs you need to have the following
1. UPMEM TOOLCHAIN INSTALLED for further infomation see the usermanual https://sdk.upmem.com/stable/index.html
2. For Homomophic Operations install the OpenFHE library see https://www.openfhe.org/

# To run the program:
mkdir -p build  
cd ./build  
cmake ..  
make  
./xxxx_host


# To note
The cmake file is merged to compile the DPU C program, host program in C++ with the capability of invoking the OpenFHE library.