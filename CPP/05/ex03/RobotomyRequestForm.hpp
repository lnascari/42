#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &p);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &p);
	~RobotomyRequestForm();
	virtual const char *execute(Bureaucrat &executor);
};

#endif