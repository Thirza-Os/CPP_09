#include "Btc.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    Btc setup = Btc(argv[1]);
    // setup.printOutcome();
    // setup.printInput();
}
