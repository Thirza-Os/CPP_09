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
        // store the first unsorted element & keep index
        int temp = vec[i + 1];
        int index = i + 1;

        //loop to shift elements, as long as the element is greater than the temp
        while (index > beginIndex && vec[index - 1] > temp)
        {
            // shift temp val to the right for as long as necessary
            vec[index] = vec[index - 1];
            index--;
        }
        // when the right spot is found, put the temp value in the right position
        vec[index] = temp;
    }
}

void    PmergeMe::vectorMergeSort(std::vector<int>& vec, int beginIndex, int endIndex)
{
    // First insertion sort, then merge the rest. 
    // set changesort to the amount where to use insertion sort. if changeSort = 1, the algorithm will work as merge sort. if changeSort = N, only insertion sort will be used
    int     changeSort = 5;
    int     middleIndex;

    // Skip merge sort while the halves are smaller than changeSort (It skips to start with insertion sort)
    // If the halves are bigger than changeSort: Merge sort will kick in!
    if (endIndex - beginIndex > changeSort)
    {
        // Take the middle index to divide the vector in halves
        middleIndex = (beginIndex + endIndex) / 2;
        // Recursively call this function for both halves
        vectorMergeSort(vec, beginIndex, middleIndex);
        vectorMergeSort(vec, middleIndex + 1, endIndex);
        mergeVec(vec, beginIndex, middleIndex, endIndex);
    }
    // Call insertion sort for each sub array
    else
        vectorInsertionSort(vec, beginIndex, endIndex);

}
