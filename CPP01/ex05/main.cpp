#include "Harl.hpp"

int main( void ) {

    std::string in;
    Harl        harl;

        std::cout << "Enter a level: ";
        std::cin >> in;
        harl.complain(in);

    return 0;
}