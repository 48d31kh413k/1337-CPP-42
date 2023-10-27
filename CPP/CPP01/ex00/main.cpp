#include "Zombie.hpp"

int main(void)
{
    Zombie zombie1("ab");
    Zombie *zombie2 = newZombie("cd");
    zombie2->announce();
    delete zombie2;
    randomChump("ef");
    return 0;
}