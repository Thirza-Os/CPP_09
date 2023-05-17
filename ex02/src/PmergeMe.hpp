#ifndef PMERGEME_HPP
# define PMERGEME_HPP


#include <string>
#include <map>
#include <iostream>
#include <vector>

class PmergeMe
{
private:
    std::vector<int>    vectorMerge;

public:
    PmergeMe();
    PmergeMe(char **input);
    ~PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe & other);

    void    printVector();
};

#endif