#ifndef BTC_HPP
# define BTC_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>

class Btc
{
private:
    std::map<std::string, float> 	    Dictionary;

public:
    Btc();
    Btc(char *filepath);
    ~Btc();
	Btc(const Btc& copy);
	Btc& operator=(const Btc & other);

    unsigned int    getSize() const;

};

#endif