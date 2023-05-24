#include "Btc.hpp"

// Unhandled: bad input such as ||||| 

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

    std::ifstream fin("data.csv");

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

	if (this != &other)
    {
		this->Dictionary = other.Dictionary;
        this->filepath = other.filepath;
    }
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
    std::string dateString;
    std::string digitString;
    struct      tm time;

    std::fstream fin(this->filepath);
    fin.getline(buffer, 1024);

    // Check if the header of the input file is correct
    if (strcmp(buffer, "date | value") != 0)
    {
        std::cerr << "Incorrect column naming: " << buffer << std::endl;
        exit(1);
    }

    // Process input line by line
    while(fin.getline(buffer, 1024))
    {
        std::string buff(buffer);

        // Check if the delimeter is present
        if (buff.find("|") == std::string::npos)
        {
            std::cout << "Bad input: " << buff << std::endl;
            continue;
        }
        else if (strcmp(buffer, "|") == 0)
        {
            std::cout << "Bad input: " << buff << std::endl;
            continue;
        }
        else
        {
            char *Date      = strtok(buffer, "|");
            dateString      = Date;

            char *charDigit = strtok(NULL, "|");
            if (charDigit == NULL || Date == NULL)
            {
                std::cout << "Error: Bad Input => " << Date <<std::endl;
                continue;
            }
            digitString     = charDigit;
        }

        // Remove whitespaces with stringstrem (get first string and save this)
            std::string         Date;
            float               Digit;

        // Using std::stringstream to read and write to a string
            std::stringstream   ss_date;
            std::stringstream   ss_digit;

            ss_date << dateString;
            ss_date >> Date;

            ss_digit << digitString;
            ss_digit >> Digit;

        // Check if the dates/digits are valid
        if (!strptime(&Date[0], "%Y-%m-%d", &time)) 
        {
            std::cout << "Error: very very BAD input => " << Date <<std::endl;
            continue;
        }
        if (signbit(Digit) == true)
        {
                std::cout << "Error: stay positive brah! " << std::endl;
                continue;
        }
        if (Digit > 1000)
        {
                std::cout << "NOOOO not so large please! " << std::endl;
                continue;
        }

        // iterate over the keys and find the value or the value clostest
        std::map <std::string, float>::iterator itr;

        // Find exact key
        itr = this->Dictionary.find(Date);
        // Check if the exact key is found, otherwise search for the upper bound
        if (itr == this->Dictionary.end())
        {
            itr = this->Dictionary.lower_bound(Date);
            // Check if the iterator is already the lowest date, if not, go one iterator back to find the lower date
            if (itr != Dictionary.begin())
                itr--;
        }

        float output = (*itr).second * Digit;

        std::cout << Date << " => " << Digit << " = " << output << std::endl;

        // unlock to check the fount date
        // std::cout << " Date found-> " << (*itr).first << std::endl;

    }

}