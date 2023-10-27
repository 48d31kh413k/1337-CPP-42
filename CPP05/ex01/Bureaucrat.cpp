#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name(""), _grade(low) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade):_name(name)
{
    if(grade < high)
        throw Bureaucrat::GradeTooHighException();
    if(grade > low)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other){
    if(other._grade < high)
        throw Bureaucrat::GradeTooHighException();
    if(other._grade > low)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & other){
    os << other.getName() << " " << other.getGrade() << std::endl;
    return os;
}

std::string Bureaucrat::getName() const{
    return this->_name;
}


int Bureaucrat::getGrade() const{
    return this->_grade;
}


void Bureaucrat::increment(){
    this->_grade--;
    if(this->_grade < high)
        throw Bureaucrat::GradeTooHighException();
}


void Bureaucrat::decrement(){

    this->_grade++;
    if(this->_grade > low)
        throw Bureaucrat::GradeTooLowException();
}


const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "TooHighException";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "TooLowException";
}

void Bureaucrat::signForm(Form& form) {
	form.beSigned(*this);
}

