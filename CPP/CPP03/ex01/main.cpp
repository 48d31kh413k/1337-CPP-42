#include "ScavTrap.hpp"

int main() {
	ScavTrap *a = new ScavTrap("1337");
	a->attack("42");
	a->takeDamage(80);
	a->beRepaired(1000);
	a->guardGate();
	return 0;
}