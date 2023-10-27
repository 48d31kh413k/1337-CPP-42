#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
	std::cout << "FragTrap: Constructor called" << std::endl;
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

    std::cout << "FragTrap: Parametrized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;

	std::cout << this->_name <<"FragTrap: Copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if(this != &other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	}
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;

	return *this;
}

void FragTrap::highFivesGuys() {
 std::cout << this->_name << " FragTrap high fives guys!!!" << std::endl;
}