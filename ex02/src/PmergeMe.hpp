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
    int                 size;

    void                vectorMergeSort(std::vector<int>& vec, int beginIndex, int endIndex);
    void                merge(std::vector<int>& vec, int beginIndex, int middleIndex, int endIndex);
    void                vectorInsertionSort(std::vector<int>& vec, int beginIndex, int endIndex);

public:
    PmergeMe();
    PmergeMe(char **input);
    ~PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe & other);

    void                performSort();
    void                printBefore();

};

#endif