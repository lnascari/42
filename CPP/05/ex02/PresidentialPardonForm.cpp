#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm(p)
{
	*this = p;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
	if(this == &p)
		return *this;
	target = p.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const char *PresidentialPardonForm::execute(Bureaucrat &executor)
{
	try {
		if (!getSigned())
			throw FormNotSignedException();
		if (executor.getGrade() > getExecute())
			throw GradeTooLowException();
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		return e.what();
	}
	return 0;
}