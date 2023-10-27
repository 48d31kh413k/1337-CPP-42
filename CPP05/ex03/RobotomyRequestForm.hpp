#ifndef ROBOTOMYREQUESTFORM_HPP_
# define ROBOTOMYREQUESTFORM_HPP_

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>
# include <string>

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		void execute(const Bureaucrat &executor) const;
	private:
		RobotomyRequestForm();
};

#endif