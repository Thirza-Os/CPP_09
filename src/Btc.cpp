#include "Btc.hpp"

Btc::Btc()
{
    std::cout << " basic contructor called" << std::endl;
}

Btc::Btc(char *filepath)
{
    std::cout << " filepath contructor called" << std::endl;

    char        buffer[1024];
    
    std::fstream fin("data.csv");

    if (!fin)
        std::cerr << "File could not be opened" << std::endl;

        while(fin.getline(buffer, 1024))
        {
            const char *dateDic = strtok(buffer, ",");
            // get the next token i.e. word before second empty space
            // NULL indicates we are using the same pointer we used previously i.e. buffer
            const char *exchange_rate = strtok(NULL, ",");
            this->Dictionary[std::string(dateDic)] = std::atof(exchange_rate);       
        }

    std::fstream finInput(filepath);

    while(finInput.getline(buffer, 1024))
    {
        std::string str = buffer;
        // if (str.size() == 0)
        //     continue;
        const char *dateInput = strtok(buffer, " | ");
        const char *value = strtok(NULL, " | ");
        this->Input.insert(std::pair<std::string, float>(dateInput, std::atof(value)));
    }
}

Btc::~Btc()
{
    std::cout << "destructor called " << std::endl;
    
    // is this necessary?
    Dictionary.clear();
    Input.clear();
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


void    Btc::printData(void)
{

   std::map <std::string, float>::iterator itr;

    //      iterating through the contents
   for (itr = this->Dictionary.begin(); itr != this->Dictionary.end(); ++itr) {
      std::cout << std::setprecision(7) << itr->first << ": " << itr->second << std::endl;
   }

   std::cout << "Size of container: " << Dictionary.size() << std::endl;
}

void    Btc::printInput(void)
{

   std::map <std::string, float>::iterator itr;

    //      iterating through the contents
   for (itr = this->Input.begin(); itr != this->Input.end(); ++itr) {
      std::cout << std::setprecision(7) << itr->first << ": " << itr->second << std::endl;
   }

   std::cout << "Size of container: " << Input.size() << std::endl;
}

void    Btc::printOutcome(void)
{

    std::map <std::string, float>::iterator itrInput;
    std::map <std::string, float>::iterator itrDictionary;

    //      iterating through the contents
   for (itrInput = this->Input.begin(); itrInput != this->Input.end(); ++itrInput) 
   {
        itrDictionary = this->Dictionary.begin();
        while ( itrDictionary != this->Dictionary.end())
        {
            if (itrInput->first.compare(itrDictionary->first) == 0)
            {
                std::cout << "first: " << itrInput->second << "second" << itrDictionary->second << std::endl;
                std::cout << itrInput->second * itrDictionary->second << std::endl;
            }
            itrDictionary++;
        }
      //std::cout << std::setprecision(7) << itr->first << ": " << itr->second << std::endl;
   }

//    std::cout << "Size of container: " << Input.size() << std::endl;
}