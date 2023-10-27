#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat: destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*(other._brain))) {
	std::cout << "Cat: copy constructor called" << std::endl;
	*this = other;
}

void Cat::makeSound() const {
	std::cout << "meow!" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "cat: assignation operator called" << std::endl;
	if (this != &other){
	this->_type = other.getType();
	*(this->_brain) = *(other._brain);
	}
	return *this;
}

