#include "Btc.hpp"

Btc::Btc()
{
    std::cout << " basic contructor called" << std::endl;
}

Btc::Btc(char *filepath)
{
    std::cout << " constructor with filepath called" << std::endl;

    
}

Btc::~Btc()
{
    std::cout << "destructor called " << std::endl;

}

Btc::Btc(const Btc &copy)
{
    std::cout << "copy constructor called " << std::endl;

    // copy all data
    *this = copy;
}

Btc& Btc::operator=(const Btc & other)
{
    std::cout << "ass operator overload called " << std::endl;

	if (this == &other)
		return *this;
    return *this;
}

