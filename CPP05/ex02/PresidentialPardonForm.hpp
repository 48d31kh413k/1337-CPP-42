#ifndef PRESIDENTIALPARDONFORM_HPP_
# define PRESIDENTIALPARDONFORM_HPP_

# include "AForm.hpp"

# include <string>

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		void execute(const Bureaucrat &executor) const;
	private:
		PresidentialPardonForm();
};

#endif