#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    // std::que is like a list of std::vectors
    
    // Vector is designed for efficient random access
    // Deque is designed to be efficient for insertion/deletions at the ends

    // Vector is a continguous array    (easy iteration/random access)
    // Deque splits it up in chunks     

    if (argc < 1)
    {
        std::cerr << "Error: Bad input" << std::endl;
        exit(1);
    }
    
    PmergeMe setup = PmergeMe(argv);
    std::cout << "Before: "; setup.print();
    setup.performSort();
    std::cout << "After: "; setup.print();
    setup.printTime();
}
