/*  This file provides the functions to interact with the DPU easily
    and aims at separating the UPMEM code from the code implementing
    the encryotion algorithsms  
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

*/ 
void run_on_dpu()
{
    auto system = DpuSet::allocate(1);
    auto dpu = system.dpus()[0];
    std::vector<long> data{0x0706050403020100l};
    std::vector<std::vector<long>> results{std::vector<long>(1)};

    dpu->load(DPU_EXE);
    dpu->copy("my_var", data);
    dpu->exec();
    dpu->log(std::cout);
    dpu->copy(results, "my_var");

    long value = results[0][0];

    std::cout << "My_Var after = 0x" << std::setfill('0') << std::setw(16) << std::hex << value << std::endl;
}