#include <dpu>
#include <iomanip>
#include <iostream>

using namespace dpu;

int main(int argc, char **argv)
{
    auto system = DpuSet::allocate(1);
    auto dpu = system.dpus()[0];
    std::vector<long> data{0x0706050403020100l};
    std::vector<std::vector<long>> results{std::vector<long>(1)};

    dpu->load("program_dpu");
    dpu->copy("my_var", data);
    dpu->exec();
    dpu->log(std::cout);
    dpu->copy(results, "my_var");

    long value = results[0][0];

    std::cout << "My_Var after = 0x" << std::setfill('0') << std::setw(16) << std::hex << value << std::endl;

    return 0;
}