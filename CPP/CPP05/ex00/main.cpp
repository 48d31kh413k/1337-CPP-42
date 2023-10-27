#include "Bureaucrat.hpp"

int main()
{
	try {
    	Bureaucrat *ab = new Bureaucrat("ab", 2);
		std::cout << *ab << std::endl;
		ab->increment();
		std::cout << *ab << std::endl;
		ab->increment();
		std::cout << *ab << std::endl;
		ab->increment();
		std::cout << *ab << std::endl;
		delete ab;
	} catch (std::exception& a) {
		std::cout << a.what() << std::endl;
	}
}