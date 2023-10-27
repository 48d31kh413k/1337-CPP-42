#include "Dog.hpp"

Dog::Dog() {
	this->_type = "Dog";
	std::cout << "Dog: default constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog: Asignation operator called" << std::endl;
	if (this != &other){
	this->_type = other.getType();
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "woof!" << std::endl;
}
