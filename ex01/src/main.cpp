#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid input " << std::endl;
        exit(1);
    }
    
    RPN testcase = RPN();
    testcase.executeExpression(argv[1]);
}
