#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: Not enough numbers" << std::endl;
        exit(1);
    }
    
    PmergeMe setup = PmergeMe(argv);
    setup.printVector();
}
