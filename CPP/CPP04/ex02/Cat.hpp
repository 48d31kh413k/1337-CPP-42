#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>


class Cat : public Animal {
	public:
		Cat(void);
		Cat(Cat const &other);
		~Cat(void);
		Cat &operator=(Cat const &other);
		void makeSound() const;
	private:
		Brain* _brain;
};

#endif
