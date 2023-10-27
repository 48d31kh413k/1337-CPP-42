#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", "none", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("presidential pardon", target, 25, 5) {
	std::cout << "Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	*this = other;
	std::cout << "Copy of Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Pardon Form destroyed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Presidential Pardon Form assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned()) {
		std::cout << "The form cannot be executed because its not signed" << std::endl;
		return ;
	}
	else if (this->getSignGrade() < executor.getGrade()) {
		std::cout << "Form  cannot be executed because the rank is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else {
			std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
}
