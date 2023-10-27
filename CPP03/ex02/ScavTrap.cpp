#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap: Constructor called" << std::endl;
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_hitPoints = 20;
}

ScavTrap::ScavTrap(std::string const name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: Parametrized constructor called" << std::endl;
}



ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: Destructor called" << std::endl;
}


ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	if(this != &other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
		std::cout << this->_name << " died" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
}

void ScavTrap::guardGate() {
    if (this->_hitPoints == 0) {
		std::cout << this->_name << "ScavTrap can't guard gate because is dead" << std::endl;
		return;
	}
	std::cout << this->_name << "ScavTrap is now in Gate keeper mode." << std::endl;
}