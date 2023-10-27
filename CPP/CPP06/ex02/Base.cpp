#include <iostream>
#include "Base.hpp"

Base::~Base() {
	std::cout << "Destructor called" << std::endl;
}
