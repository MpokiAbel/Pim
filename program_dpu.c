#include <mram.h>
#include <stdint.h>
#include <stdio.h>

__mram uint64_t my_var; // Initialized by the host application

int main()
{
    uint64_t data = my_var;
    printf("My_Var before = 0x%016lx\n", data);

    my_var = data + 1;

    return 0;
}