#include "WrongCat.hpp"

WrongCat::WrongCat(void){
	_type = "WrongCat";
	std::cout << "WrongCat: Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat: Destructor Called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other) {
	std::cout << "WrongCat: Copy Constructor Called" << std::endl;
	*this = other;
}

WrongCat	&WrongCat::operator=(WrongCat const &other){
	if (this != &other){
	this->_type = other.getType();
	}
	std::cout << "WrongCat: Copy Assignment Operator Called" << std::endl;
	return *this;
}

void		WrongCat::makeSound(void)const{
	std::cout << "Wrongmeow!" << std::endl;
}
