#include "Btc.hpp"

Btc::Btc()
{
    std::cout << " basic contructor called" << std::endl;
}

Btc::Btc(char *filepath)
{
    std::cout << " filepath contructor called" << std::endl;
    
    char        buffer[1024];

    if (strcmp(filepath, "input.txt") != 0)
    {
        std::cerr << "Incorrect input file" << std::endl;
        exit(1);
    }

    this->filepath = filepath;

    std::fstream fin("data.csv");

    if (!fin)
    {
        std::cerr << "File could not be opened" << std::endl;
        exit(1);
    }

        while(fin.getline(buffer, 1024))
        {
            const char *dateDic = strtok(buffer, ",");
            // get the next token i.e. word before second empty space
            // NULL indicates we are using the same pointer we used previously i.e. buffer
            const char *exchange_rate = strtok(NULL, ",");
            this->Dictionary[std::string(dateDic)] = std::atof(exchange_rate);       
        }

    std::fstream finInput(filepath);
}

Btc::~Btc()
{
    std::cout << "destructor called " << std::endl;
}

Btc::Btc(const Btc &copy)
{
    std::cout << "copy constructor called " << std::endl;

    *this = copy;
}

Btc& Btc::operator=(const Btc & other)
{
    std::cout << "ass operator overload called " << std::endl;

	if (this == &other)
		return *this;
    return *this;
}


void    Btc::printDictionary(void)
{

   std::map <std::string, float>::iterator itr;

    //      iterating through the contents
   for (itr = this->Dictionary.begin(); itr != this->Dictionary.end(); ++itr) {
      std::cout << std::setprecision(7) << itr->first << ": " << itr->second << std::endl;
   }

   std::cout << "Size of container: " << Dictionary.size() << std::endl;
}


void    Btc::printOutcome()
{
    char        buffer[1024];
    struct      tm time;

    std::fstream fin(this->filepath);
    fin.getline(buffer, 1024);
    if (strcmp(buffer, "date | value") != 0)
    {
        std::cerr << "Incorrect input file content" << std::endl;
        exit(1);
    }
    while(fin.getline(buffer, 1024))
    {
        char *Date = strtok(buffer, "|");
        char *charDigit = strtok(NULL, "|");

        std::cout << isdigit(charDigit[strlen(charDigit) - 1]) << std::endl;

        if ((charDigit[0] != ' ') || (!isdigit(Date[0])) || (!isdigit(charDigit[strlen(charDigit) - 1])))
        {
                std::cout << "Error: wrong input format " << charDigit << std::endl;
                break;
        }
        if (!strptime(Date, "%Y-%m-%d", &time)) 
        {
            std::cout << "Error: bad input => " << Date <<std::endl;
            continue;
        }
        if (charDigit[1] == '-')
        {
                std::cout << "Error: not a positive number => " << charDigit << std::endl;
                break;
        }
        for (size_t i = 1; i < strlen(charDigit); i++)
        {
            if (charDigit[i] != '.' && !isdigit(charDigit[i]))
            {
                std::cout << "Error: not a valid number => " << charDigit <<std::endl;
                break;
            }
        }
        std::cout << "Correct: " << Date << charDigit << std::endl;

    }

}