#include "Btc.hpp"

Btc::Btc()
{
    std::cout << " basic contructor called" << std::endl;
}

Btc::Btc(char *filepath)
{
    std::cout << " constructor with filepath called" << std::endl;
    
    char        buffer[1024];
    
    std::fstream fin(filepath);
    if (!fin)
        std::cerr << "File could not be opened" << std::endl;

    while(fin.getline(buffer, 1024))
    {
        const char * date = strtok(buffer, ",");
        const char * exchange_rate = strtok(NULL, ",");
        this->Dictionary[std::string(date)] = std::atof(exchange_rate);
    }

    // PRINTING
   std::map <std::string, float>::iterator itr;

   //iterating through the contents
   for (itr = this->Dictionary.begin(); itr != this->Dictionary.end(); ++itr) {
      std::cout << std::setprecision(7) << itr->first << ": " << itr->second << std::endl;
   }


    
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

