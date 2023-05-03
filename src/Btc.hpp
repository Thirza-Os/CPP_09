#ifndef BTC_HPP
# define BTC_HPP


#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <limits.h>
#include <ctime>
#include <ctype.h>

// Map: unique keys.
// Multimap: same keys are ok.

class Btc
{
private:
    std::map<std::string, float>            Dictionary;
    char                                    *filepath;

public:
    Btc();
    Btc(char *filepath);
    ~Btc();
	Btc(const Btc& copy);
	Btc& operator=(const Btc & other);

    void    printDictionary();
    void    printOutcome();
};

#endif