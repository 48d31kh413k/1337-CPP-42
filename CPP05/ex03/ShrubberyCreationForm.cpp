#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("shrubbery creation", "none", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
		: AForm("shrubbery creation", target, 145, 137) {
	std::cout << "Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
		: AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	*this = other;
	std::cout << "Copy of Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Creation Form destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Shrubbery Creation Form assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned()) {
		std::cout << "The form cannot be executed because its not signed" << std::endl;
		return ;
	}
	else if (this->getSignGrade() < executor.getGrade()) {
		std::cout << "Form  cannot be executed because the rank is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else {
	std::ofstream out;

	out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
	out << "      /\\      " << std::endl;
	out << "     /\\*\\    " << std::endl;
	out << "    /\\O\\*\\    " << std::endl;
	out << "   /*/\\/\\/\\   " << std::endl;
	out << "  /\\O\\/\\*\\/\\  " << std::endl;
	out << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	out << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	out << "      ||      " << std::endl;
	out << "      ||      " << std::endl;
	out << "      ||      " << std::endl;
	}
}
