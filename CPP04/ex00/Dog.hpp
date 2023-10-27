#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
	public:
		Dog(void);
		Dog(Dog const &other);
		~Dog(void);
		Dog &operator=(Dog const &other);
		void makeSound() const;
};

#endif
