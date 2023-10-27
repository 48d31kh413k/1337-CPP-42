#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	 std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "Parametrized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	 std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {	std::cout << "Destructor called" << std::endl;}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
		std::cout << this->_name << " died" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
		std::cout << this->_name << " died" << std::endl;
		return;
	}
	std::cout << this->_name << " ClapTrap has taken " << amount << " points of damage" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
		std::cout << this->_name << " died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
		std::cout << this->_name << " died" << std::endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << this->_name << " ClapTrap has repaired " << amount << " hit points" << std::endl;
}