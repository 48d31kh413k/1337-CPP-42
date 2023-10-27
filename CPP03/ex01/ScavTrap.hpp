#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const &other);
		~ScavTrap(void);
		ScavTrap &operator=(ScavTrap const &other);
		void attack(const std::string& target);
		void	guardGate();
	private:

};

#endif