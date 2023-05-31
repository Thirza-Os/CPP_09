#include "PmergeMe.hpp"                                                 
                                                  
void    PmergeMe::mergeVec(std::vector<int>& vec, int beginIndex, int middleIndex, int endIndex)
{
    // set up two vectors for the right and left half
    int vec1 = middleIndex - beginIndex + 1;
    int vec2 = endIndex - middleIndex;

    std::vector<int> leftVec(vec1);
    std::vector<int> rightVec(vec2);

    // fill the vectors
    for (int i = 0; i < vec1; i++)
        leftVec[i] = vec[beginIndex + i];
    for (int i = 0; i < vec2; i++)
        rightVec[i] = vec[middleIndex + 1 + i];

    // set indexes to keep track of the subvectors
    int rightIndex = 0;
    int leftIndex = 0;
    
    // merge the right and left subvectors back in the original vec, in order
    // 4 options: 
    //  1 & 2:  Either of the vectors is already merged
    //  2 & 3   Either   
    for (int i = beginIndex; i <= endIndex; i++)
    {
        // if the right index reaches the end of that index, all elements of the right vec has been merged.
        // fill remainder with left vec
        if (rightIndex == vec2)
        {
            vec[i] = leftVec[leftIndex];
            leftIndex++;
        }
        // if the left index reaches the end of that index, all elements of the left vec has been merged.
        // fill remainder with right vec.
        else if (leftIndex == vec1)
        {
            vec[i] = rightVec[rightIndex];
            rightIndex++;
        }
        // if the element of the right vector is bigger than the item of the left, add the smaller element (left) to the vec.
        else if (rightVec[rightIndex] > leftVec[leftIndex])
        {
            vec[i] = leftVec[leftIndex];
            leftIndex++;
        }
        // else: the element of the left vector is bigger than the item of the right, add the smaller element (right) to the vec.
        else
        {
            vec[i] = rightVec[rightIndex];
            rightIndex++;
        }
    }
}

void    PmergeMe::vectorInsertionSort(std::vector<int>& vec, int beginIndex, int endIndex)
{
    for (int i = beginIndex; i < endIndex; i++)
    {
        // 1. Store the first unsorted element & keep this index (the first time this is index 1)
        // 2. Check  if we are not at the begining && if the value of the first unsorted element is smaller than the previous value.
        // 3. If no: skip and keep in place.
        // 4. If yes: Swap the elements.
        int temp = vec[i + 1];
        int index = i + 1;

        while (index > beginIndex && vec[index - 1] > temp)
        {
            vec[index] = vec[index - 1];
            index--;
        }
        vec[index] = temp;
    }
}

void    PmergeMe::vectorMergeSort(std::vector<int>& vec, int beginIndex, int endIndex)
{
    // 1. Divide in subvectors until 'Change'
    // 2. Use insertion sort for the subvectors of 'change' size.
    // 3. Use merge sort for the remainder of the subvectors

    // changesort: if changeSort = 1, the algorithm will work as merge sort. if changeSort = N, only insertion sort will be used

    int     changeSort = 5;
    int     middleIndex;

    if (endIndex - beginIndex > changeSort)
    {
        // Take the middle index to divide  the vector in halves
        middleIndex = (beginIndex + endIndex) / 2;

        // Recursively call this function for both halves until halves of size 'change' is left
        vectorMergeSort(vec, beginIndex, middleIndex);
        vectorMergeSort(vec, middleIndex + 1, endIndex);

        // call merge function
        mergeVec(vec, beginIndex, middleIndex, endIndex);
    }
    // Call insertion sort for each sub array of changeSort size
    else
        vectorInsertionSort(vec, beginIndex, endIndex);
}
