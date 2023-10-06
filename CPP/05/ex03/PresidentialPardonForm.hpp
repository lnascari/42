#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &p);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &p);
	~PresidentialPardonForm();
	virtual const char *execute(Bureaucrat &executor);
};

#endif