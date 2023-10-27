#include "AForm.hpp"


void AForm::checkGrade(int grade) {
	if (grade < high) throw Bureaucrat::GradeTooHighException();
	if (grade > low) throw Bureaucrat::GradeTooLowException();
}


AForm::AForm() : _signed(false), _name("AForm"), _target("none"), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string& name, const std::string& target, int signGrade, int executeGrade) : _signed(false), _name(name), _target(target), _signGrade(signGrade), _executeGrade(executeGrade) {
	checkGrade(signGrade);
	checkGrade(executeGrade);
	std::cout << "AForm created" << std::endl;
}

AForm::AForm(const AForm& other): _signed(other._signed),  _name(other._name),  _signGrade(other._signGrade),  _executeGrade(other._executeGrade) {
	std::cout << "Copy of AForm created" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destroyed" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

const std::string& AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_signed;
}

int AForm::getSignGrade() const {
	return this->_signGrade;
}

int AForm::getExecuteGrade() const {
	return this->_executeGrade;
}

const std::string& AForm::getTarget() const {
	return this->_target;
}

void AForm::checkExecuted(const Bureaucrat& bureaucrat) const {
	if (this->_signed == false) {
		std::cout << bureaucrat.getName() << " can't execute " << this->_name << std::endl;
		throw AForm::NotSigned();
	}
	if (bureaucrat.getGrade() > this->_executeGrade) {
		std::cout << bureaucrat.getName() << " can't execute " << this->_name << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::cout << bureaucrat.getName() << " executed " << this->_name << std::endl;
	this->execute(bureaucrat);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade) {
		this->_signed = true;
		std::cout << bureaucrat.getName() << " has signed " << this->_name << std::endl;
	} else {
		std::cout << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		throw AForm::GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Exception: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Exception: grade too low";
}

const char* AForm::NotSigned::what() const throw() {
	return "Exception: form is not signed so it can't be executed";
}

std::ostream& operator<<(std::ostream& os, const AForm& instance) {
	os << "AForm " << instance.getName()
		<< ", status: " << (instance.getSigned() ? "signed" : "not signed")
		<< ", sign grade: " << instance.getSignGrade()
		<< ", execute grade: " << instance.getExecuteGrade()
		<< std::endl;
	return os;
}