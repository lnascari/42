#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request form", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &p) : AForm(p)
{
	*this = p;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &p)
{
	if(this == &p)
		return *this;
	target = p.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const char *RobotomyRequestForm::execute(Bureaucrat &executor)
{
	try {
		if (!getSigned())
			throw FormNotSignedException();
		if (executor.getGrade() > getExecute())
			throw GradeTooLowException();
		std::cout << "some drilling noises" << std::endl;
		srand((unsigned)time(0)); 
		if (rand() % 2)
			std::cout << target << " has been robotomized" << std::endl;
		else
			std::cout << "robotomy failed" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		return e.what();
	}
	return 0;
}