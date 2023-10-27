#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"



int main(void)
{
	Intern		i;
	AForm		*f;
	Bureaucrat	b("ab", 1);
	{
		f = i.makeForm("shrubbery creation", "cd");

		if (f)
		{
			std::cout << *f << std::endl;
			b.signForm(*f);
			f->execute(b);

			delete (f);
		}
	}

}
