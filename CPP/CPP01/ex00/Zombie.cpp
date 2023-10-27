#include "Zombie.hpp"
#include <iomanip>

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << this->_name << ": destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}