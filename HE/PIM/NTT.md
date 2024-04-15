Unlike polynomial addition, which operates element-wise (coefficient-wise), schoolbook polynomial multiplication is not applied in the same manner. It requires operations to be performed with a complexity of n², making it unsuitable for larger degree polynomials.

To address this, techniques such as the Number Theoretic Transform (NTT) are adopted to transform polynomials, allowing for element-wise multiplication with quasi-linear complexity (nlogn).

By definition, NTT is a variant of DFT. Unlike DFT, which operates on a complex ring to transform polynomials, NTT utilizes integer polynomials and a twiddle factor of its n-th root of unity. Moreover, the use of integers in NTT makes it popular as it eliminates the need to deal with precision problems. These transformations find widespread use in signal processing, typically representing shifts between the frequency and time domains. However, in polynomials, NTT lacks a direct physical interpretation. Yet, its preserved convolution properties are invaluable for calculating polynomial multiplications.  

A drawback of classical NTT is its complexity of n², primarily stemming from the final transformation level necessitating matrix multiplication. To overcome this, FFT algorithms are employed, reducing NTT's complexity to quasi-linear (nlogn).

Some popular FFT algorithms include the Cooley-Tukey (CT) algorithm for calculating the Forward NTT and the Gentleman-Sande (GS) algorithm for computing the inverse NTT. Both aim to reduce complexity and speed up the matrix multiplication process essential for NTT transformations. They employ a "divide and conquer" approach, dividing the calculation of NTT and iNTT into two n/2 parts, requiring n to be a power of two for the process to repeat for all coefficients. Moreover, the dividing technique differs for NTT and iNTT. NTT is usually divided based on the summation of its index parity, while iNTT is separated by the lower and upper halves of the summation.	

How to parallelise the NTT ?


Explain What are they doing exacly and what ca we parallelise and offload to DPUs: 
1. At the moment i know is to offload the butterflies. 
2. Look at how the HEXL impliments the operations of the tranformations.

NTT convolutions
We have the
