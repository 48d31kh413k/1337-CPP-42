#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal: default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : Animal(other) {
	std::cout << "WrongAnimal: copy constructor called" << std::endl;
	*this = other;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong animal sound" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal: assignation operator called" << std::endl;
	if (this != &other){
	this->_type = other.getType();
	}
	return *this;
}

