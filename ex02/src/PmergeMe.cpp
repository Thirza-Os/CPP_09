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

        for (int i = 1; input[i]; i++)
        {
            try
            {
                digit = std::stoi(input[i]);
                if (digit > 4000)
                {
                    std::cerr << "Error: Number is too high! " << std::endl;
                    exit(1);
                }
                this->vectorMerge.push_back(int(digit));
            }
            catch (...)
            {
                std::cerr << "Error: incorrect input" << std::endl;
                exit(1);
            }
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


void    PmergeMe::printVector(void)
{

   std::vector<int>::iterator itr;

    //      iterating through the contents
   for (itr = this->vectorMerge.begin(); itr != this->vectorMerge.end(); ++itr) {
      std::cout << *itr << std::endl;
   }

   std::cout << "Size of container: " << vectorMerge.size() << std::endl;
}
