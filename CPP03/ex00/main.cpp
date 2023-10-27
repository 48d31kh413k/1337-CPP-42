#include "ClapTrap.hpp"

int main() {
	ClapTrap *a = new ClapTrap("42");
	ClapTrap *b = new ClapTrap("42");
	b = a;
	a->attack("1337");
	a->takeDamage(5);
	a->beRepaired(10);
	b->attack("1337");
	b->takeDamage(5);
	b->beRepaired(10);
	return 0;
}