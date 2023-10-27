#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;
    Zombie *Zombiehorde = new Zombie[N];
    for (int i = 0; i < N; i++) {
		Zombiehorde[i].setName(name);
	}
    return Zombiehorde;
    
}