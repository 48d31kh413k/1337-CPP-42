#ifndef SHRUBBERYCREATIONFORM_HPP_
# define SHRUBBERYCREATIONFORM_HPP_

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		void execute(const Bureaucrat &executor) const;
	private:
		ShrubberyCreationForm();
};

#endif