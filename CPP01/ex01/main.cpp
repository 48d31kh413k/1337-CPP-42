#include "Zombie.hpp"

int main(void)
{
    int size = 5;
	Zombie *zhorde;
	zhorde = zombieHorde(size, "abdelkhalek");
	for (int i = 0; i < size; i++) zhorde[i].announce();
	delete[] zhorde;
}