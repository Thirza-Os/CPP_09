#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    // std::que is like a list of std::vectors
    // Deque is designed to be efficient for insertion/deletions at the ends
    // Vector is designed for efficient random access

    // In this algorithm: Merging allows for a lot of insertions/deletions
    // Memory allocation: vector stores contiguous: it takes a lot of time to move this around. Deque stores it in chunks, faster to move.

    // -> for sequential access vector would be more efficient

    if (argc < 2)
    {
        std::cerr << "Error: Not enough numbers" << std::endl;
        exit(1);
    }
    
    PmergeMe setup = PmergeMe(argv);
    std::cout << "Before: "; setup.print();
    setup.performSort();
    std::cout << "After: "; setup.print();
    setup.printTime();
}
