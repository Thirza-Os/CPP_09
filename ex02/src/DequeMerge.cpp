#include "PmergeMe.hpp"

void    PmergeMe::mergeDeque(std::deque<int>& que, int beginIndex, int middleIndex, int endIndex)
{
    // set up two quues for the right and left half
    int que1 = middleIndex - beginIndex + 1;
    int que2 = endIndex - middleIndex;

    std::deque<int> leftque(que1);
    std::deque<int> rightque(que2);

    // fill the ques
    for (int i = 0; i < que1; i++)
        leftque[i] = que[beginIndex + i];
    for (int i = 0; i < que2; i++)
        rightque[i] = que[middleIndex + 1 + i];

    // set indexes to keep track of the subques
    int rightIndex = 0;
    int leftIndex = 0;
    
    // merge the right and left subques back in the original que, in order  
    for (int i = beginIndex; i <= endIndex; i++)
    {
        // if the right index reaches the end of that index, all elements of the right que has been merged.
        // fill remainder with left que
        if (rightIndex == que2)
        {
            que[i] = leftque[leftIndex];
            leftIndex++;
        }
        // if the left index reaches the end of that index, all elements of the left que has been merged.
        // fill remainder with right que.
        else if (leftIndex == que1)
        {
            que[i] = rightque[rightIndex];
            rightIndex++;
        }
        // if the element of the right que is bigger than the item of the left, add the smaller element (left) to the que.
        else if (rightque[rightIndex] > leftque[leftIndex])
        {
            que[i] = leftque[leftIndex];
            leftIndex++;
        }
        // else: the element of the left que is bigger than the item of the right, add the smaller element (right) to the que.
        else
        {
            que[i] = rightque[rightIndex];
            rightIndex++;
        }
    }

 
}

void    PmergeMe::dequeInsertionSort(std::deque<int>& deque, int beginIndex, int endIndex)
{
    for (int i = beginIndex; i < endIndex; i++)
    {
        // store the first unsorted element & keep index
        int temp = deque[i + 1];
        int index = i + 1;

        //loop to shift elements, as long as the element is greater than the temp
        while (index > beginIndex && deque[index - 1] > temp)
        {
            // shift temp val to the right for as long as necessary
            deque[index] = deque[index - 1];
            index--;
        }
        // when the right spot is found, put the temp value in the right position
        deque[index] = temp;
    }
}

void    PmergeMe::dequeMergeSort(std::deque<int>& deque, int beginIndex, int endIndex)
{
    // First insertion sort, then merge the rest. 
    // set changesort to the amount where to use insertion sort. if K = 1, the algorithm will work as merge sort. if K = N, only insertion sort will be used
    int     changeSort = 5;
    int     middleIndex;

    // Skip merge sort while the halves are smaller than K (It skips to start with insertion sort)
    // If the halves are bigger than K: Merge sort will kick in!
    if (endIndex - beginIndex > changeSort)
    {
        // Take the middle index to divide the que in halves
        middleIndex = (beginIndex + endIndex) / 2;
        // Recursively call this function for both halves
        dequeMergeSort(deque, beginIndex, middleIndex);
        dequeMergeSort(deque, middleIndex + 1, endIndex);
        mergeDeque(deque, beginIndex, middleIndex, endIndex);
    }
    // Call insertion sort for each sub array of size K
    else
        dequeInsertionSort(deque, beginIndex, endIndex);
}