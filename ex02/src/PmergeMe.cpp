#include "PmergeMe.hpp"

// does not handle: multiple ||| / chars in the digit input
// if | but no value: you get nothing

PmergeMe::PmergeMe()
{
    std::cout << " basic contructor called" << std::endl;
}

PmergeMe::PmergeMe(char **input)
{
    std::cout << " filepath contructor called " << std::endl;

    int                 digit;

    // Retrieve input, check for invalid entries and fill vector/list
    for (int i = 1; input[i]; i++)
    {
        try
        {
            digit = std::stoi(input[i]);
            if (digit < 0)
            {
                std::cerr << "Error: No negative numbers please " << std::endl;
                exit(1);
            }
            this->vectorMerge.push_back(int(digit));
            this->dequeMerge.push_back(int(digit));
        }
        catch (...)
        {
            std::cerr << "Error: Fix your input please" << std::endl;
            exit(1);
        }
        // check if there is enough input/too much input
        if (this->vectorMerge.size() > 3000)
        {
            std::cerr << "Error: Fix the amount of integers please" << std::endl;
            exit(1);
        }
        this->size = this->vectorMerge.size();
    }
}

PmergeMe::~PmergeMe()
{
    std::cout << "destructor called " << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    std::cout << "copy constructor called " << std::endl;

    *this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe & other)
{
    std::cout << "ass operator overload called " << std::endl;

	if (this == &other)
		return *this;
    return *this;
}


                                                    // Vector sort functions

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
    // set changesort to the amount where to use insertion sort. if K = 1, the algorithm will work as merge sort. if K = N, only insertion sort will be used
    int     changeSort = 5;
    int     middleIndex;

    // Skip merge sort while the halves are smaller than K (It skips to start with insertion sort)
    // If the halves are bigger than K: Merge sort will kick in!
    if (endIndex - beginIndex > changeSort)
    {
        // Take the middle index to divide the vector in halves
        middleIndex = (beginIndex + endIndex) / 2;
        // Recursively call this function for both halves
        vectorMergeSort(vec, beginIndex, middleIndex);
        vectorMergeSort(vec, middleIndex + 1, endIndex);
        mergeVec(vec, beginIndex, middleIndex, endIndex);
    }
    // Call insertion sort for each sub array of size K
    else
        vectorInsertionSort(vec, beginIndex, endIndex);

}

                                                        // List sort functions


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

                                                            // Call the sorting algorithms

void    PmergeMe::performSort()
{
        // Vector sort
    int beginIndex = 0;
    int endIndex = this->size - 1;

    std::clock_t startVecTime = std::clock();

    vectorMergeSort(this->vectorMerge, beginIndex, endIndex);

    std::clock_t endVecTime = std::clock();
    this->timeVec = endVecTime - startVecTime;


        // List sort
    std::clock_t startQueTime = std::clock();

    dequeMergeSort(this->dequeMerge, beginIndex, endIndex);

    std::clock_t endQueTime = std::clock();
    this->timeDeque = endQueTime - startQueTime;

}

void    PmergeMe::print(void)
{

   std::vector<int>::iterator itr;

    //      iterating through the contents
   for (itr = this->vectorMerge.begin(); itr != this->vectorMerge.end(); ++itr) {
      std::cout << *itr << " " ;
   }
    std::cout << std::endl;


    //      PRINT QUE
//     std::deque<int>::iterator ditr;

//    for (ditr = this->dequeMerge.begin(); ditr != this->dequeMerge.end(); ++ditr) {
//       std::cout << *ditr << " " ;
//    }
//     std::cout << std::endl;
}

void    PmergeMe::printTime(void)
{
    std::cout << "Time to process a range of " << this->size << " elements with std::vector: " << this->timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << this->size << " elements with std::que: " << this->timeDeque << " us" << std::endl;
}
