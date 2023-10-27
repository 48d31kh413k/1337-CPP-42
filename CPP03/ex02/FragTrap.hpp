#ifndef FragTrap_HPP
#define FragTrap_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);
		FragTrap &operator=(FragTrap const &src);
		void	highFivesGuys();
	private:

};

#endif