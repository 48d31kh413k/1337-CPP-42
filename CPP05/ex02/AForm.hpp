#ifndef AForm_HPP_
# define AForm_HPP_

# include "Bureaucrat.hpp"

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
	public:
		AForm(const std::string& name, const std::string& target, int signGrade, int executeGrade);
		AForm(const AForm& AForm);
		virtual ~AForm();

		AForm& operator=(const AForm& other);

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		 void	checkExecuted(const Bureaucrat &executor ) const;

		const std::string& getName() const;
		const std::string& getTarget() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void checkGrade(int grade);
	private:
		AForm();

		bool _signed;

		const std::string _name;
		const std::string _target;
		const int _signGrade;
		const int _executeGrade;
	public:
		class GradeTooHighException : public std::exception {
			public: const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public: const char* what() const throw();
		};
		class NotSigned : public std::exception {
			public: const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& instance);

#endif
