# In-Memory Processing of Encrypted data

## Objective:
Evaluate the types of operations that can be done over encrypted data on UPMEM chips and that provide performance benefits over migrating the data to main memory.

The main idea is to evaluate the types of operations that can be done over encrypted data on UPMEM Chips and that provide performance benefits over migrating the data to main memory.

The operations include but not limited to:
1. Search/query
2. Filter
3. Summarize/aggregate/Count

ToDo: Review the steps here
## Steps:
We would like to compare the cost of several scenarios:
1. Implement the algorithm with UPMEM SDK and do the operation directly on PIM DRAM.
2. Copy data from PIM DRAM to main CPU; do the operation over encrypted data on CPU.
3. Copy data from PIM DRAM to main CPU and do the operation in SGX enclave (decrypting it in the enclave).
4. As baseline but insecure: copy data from PIM DRAM to main CPU, decrypt, and do the operation over plain data on CPU.

This would provide us with a good survey of the kind of algorithms we can (relatively easily) execute on PIM DRAM over encrypted data, for which we have performance benefits.

For more details on progress of the project click [here](UPMEM.md) 
