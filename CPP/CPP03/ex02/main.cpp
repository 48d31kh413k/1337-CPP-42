#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
	FragTrap *b = new FragTrap("1337");
	b->attack("42");
	b->takeDamage(50);
	b->beRepaired(1);
	b->highFivesGuys();
	return 0;
}