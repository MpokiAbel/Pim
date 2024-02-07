/*
    This is the dpu program for the simple-integers BFVrns (Integer Arithmetics).
    This program aims to run the FHE operations i.e Additions, Multiplication and
    Rotations on the DPU.We could have multiple DPU's running these programs separately,
    however as a starting point we start with addition.
*/
#include <mram.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>


__host int64_t my_var[14]; // Initialized by the host application

/*
    ToDo: 1.Figure out whats the arrangement of data is to perform the addition operations.
        

*/

int main()
{
    // uint64_t data = my_var;
    // printf("My_Var before = 0x%016lx\n", my_var[1]);

    for (int i = 0; i < 14; i++)
    {
        printf("%" PRId64 " ", my_var[i]);
    }
    // my_var = data + 1;
    printf("\n");
    return 0;
}