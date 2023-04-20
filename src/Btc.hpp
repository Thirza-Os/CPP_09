#ifndef BTC_HPP
# define BTC_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>

// Map: unique keys.
// Multimap: same keys are ok.

class Btc
{
private:
    std::map<std::string, float>            Dictionary;
    std::multimap<std::string, float>       Input;

public:
    Btc();
    Btc(char *filepath);
    ~Btc();
	Btc(const Btc& copy);
	Btc& operator=(const Btc & other);

    void    printData();
    void    printInput();
    void    printOutcome();
};

#endif