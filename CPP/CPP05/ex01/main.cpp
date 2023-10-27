#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>



int main()
{
	try{
		Bureaucrat* ab = new Bureaucrat("ab", 150);
		Bureaucrat* ac = new Bureaucrat("ac", 20);
		Form* cd = new Form("cd", 30, 10);

		std::cout <<  std::endl << *cd << std::endl;
		try {
			ab->signForm(*cd);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl << *cd << std::endl;
		try {
			cd->beSigned(*ac);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}


		delete ab;
		delete cd;
		delete ac;
	}
	catch (std::exception& e) {
			std::cout << e.what() << std::endl;
	}
	return 0;
}