#include "Btc.hpp"

int main(int argc, char *argv[])
{
    std::cout << *argv << std::endl;
    if (argc != 2)
        std::cerr << "Wrong file input" << std::endl;

    Btc test = Btc();
    Btc test2 = Btc(argv[1]);
    
}
