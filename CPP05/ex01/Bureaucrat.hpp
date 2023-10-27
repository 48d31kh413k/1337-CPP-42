#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

#define low 150
#define high 1

class Form;

class Bureaucrat{
    public:
    //canonical form
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
    //accessors
        std::string getName() const;
        int getGrade() const;
    //member function
        void increment();
        void decrement();
        void signForm(Form& form);
    //Nested class
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
    
    private:
        const std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream & os, Bureaucrat const & other);

#endif

