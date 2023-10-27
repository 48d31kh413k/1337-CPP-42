#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"



int main(void)
{
	 try {
        Bureaucrat a("a", 130);
        Bureaucrat b("b", 140);
		ShrubberyCreationForm c("c");
        std::cout << c << std::endl;
        a.signForm(c);
        std::cout << std::endl;
		a.executeForm(c);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
