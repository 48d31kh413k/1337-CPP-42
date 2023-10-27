#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
	public:
		Brain(void);
		Brain(Brain const &other);
		~Brain(void);
		Brain &operator=(Brain const &other);
	private:
		std::string _ideas[100];
};

#endif
