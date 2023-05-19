#ifndef PMERGEME_HPP
# define PMERGEME_HPP


#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
private:
    std::vector<int>    vectorMerge;
    std::deque<int>     dequeMerge;
    std::clock_t        timeVec;
    std::clock_t        timeDeque;


    int                 size;

    void                vectorMergeSort(std::vector<int>& vec, int beginIndex, int endIndex);
    void                mergeVec(std::vector<int>& vec, int beginIndex, int middleIndex, int endIndex);
    void                vectorInsertionSort(std::vector<int>& vec, int beginIndex, int endIndex);

    void                dequeMergeSort(std::deque<int>& deque, int beginIndex, int endIndex);
    void                mergeDeque(std::deque<int>& deque, int beginIndex, int middleIndex, int endIndex);
    void                dequeInsertionSort(std::deque<int>& deque, int beginIndex, int endIndex);

public:
    PmergeMe();
    PmergeMe(char **input);
    ~PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe & other);

    void                performSort();
    void                print();
    void                printTime();

};

#endif