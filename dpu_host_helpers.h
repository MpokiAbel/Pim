/*  This file provides the functions to interact with the DPU easily
    and aims at separating the UPMEM code from the code implementing
    the homomophic encryption algorithsms
*/

#include <dpu>
#include <iomanip>
#include <iostream>

#ifndef DPU_EXE
#define DPU_EXE "program_dpu"
#endif

using namespace dpu;

/*
    run_on_dpu runs the data supplied on the dpu, at the moment
    it runs on a single dpu and data is not passed.
    This is just for testing once Requirements are cleary defined


    TODO :
    1. Fix the Dynamic variable, by passing them in the function i.e DPU_NUM,Data and a pointer for the return variables
    2. Make sure that the variables comply with the data type of the passed variables i.e USE templates.
    QN. How to handle templates on the
*/
template <class T>
void run_on_dpu(const std::vector<T> &data, int dpu_num = 1)
{
    auto system = DpuSet::allocate(dpu_num);
    std::vector<std::vector<T>> results{std::vector<T>(1)};

    for (int i = 0; i < dpu_num; i++)
    {
        auto dpu = system.dpus()[i];

        dpu->load(DPU_EXE);
        dpu->copy("my_var", data);
        dpu->exec();
        dpu->log(std::cout);
        dpu->copy(results, "my_var");

        long value = results[0][0];

        std::cout << "DPU " << i << " My_Var after = 0x" << std::setfill('0') << std::setw(16) << std::hex << value << std::endl;
    }
}
