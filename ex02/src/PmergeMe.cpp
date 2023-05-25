#include "PmergeMe.hpp"

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

	if (this != &other)
	{
        this->vectorMerge   = other.vectorMerge;
        this->dequeMerge    = other.dequeMerge;
        this->timeVec       = other.timeVec;
        this->timeDeque     = other.timeDeque;
        this->size          = other.size;
    }
    return *this;
}                                                           // Call the sorting algorithms

void    PmergeMe::performSort()
{
        // Vector sort
    int beginIndex = 0;
    int endIndex = this->size - 1;

    std::clock_t startVecTime = std::clock();

    vectorMergeSort(this->vectorMerge, beginIndex, endIndex);

    std::clock_t endVecTime = std::clock();
    this->timeVec = endVecTime - startVecTime;


        // deque sort
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


                                                            //      UNLOCK TO PRINT QUE
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
