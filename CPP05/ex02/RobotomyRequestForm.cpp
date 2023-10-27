#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"



RobotomyRequestForm::RobotomyRequestForm()
		: AForm("robotomy request", "none", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
		: AForm("robotomy request", target, 72, 45) {
	std::cout << "Robotomy Request AForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
		: AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	*this = other;
	std::cout << "Copy of Robotomy Request AForm created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy Request AForm destroyed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Robotomy Request AForm assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned()) {
		std::cout << "The form cannot be executed because its not signed" << std::endl;
		return ;
	}
	else if (this->getSignGrade() < executor.getGrade()) {
		std::cout << "Form  cannot be executed because the rank is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
	std::srand(std::time(NULL)); // use current time as seed for random generator

	std::cout << "* some drilling noises *" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << this->getTarget() << " has been robotomized succesfully" << std::endl;
	} else {
		std::cout << "Failed to robotomized " << this->getTarget() << std::endl;
	}
	}
}
