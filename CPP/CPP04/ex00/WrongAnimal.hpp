#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include "Animal.hpp"
#include <iostream>

class WrongAnimal : public Animal {
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &other);
	~WrongAnimal(void);
	WrongAnimal &operator=(WrongAnimal const &other);
	void makeSound() const;
};



#endif
