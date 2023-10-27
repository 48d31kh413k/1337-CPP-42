#ifndef INTERN_HPP_
# define INTERN_HPP_

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# include <string>

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string name, std::string target);
	private:
		typedef struct s_forms {
			std::string name;
			AForm *forms;
		} t_forms;
};

#endif