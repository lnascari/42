#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &p);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &p);
	~ShrubberyCreationForm();
	virtual const char *execute(Bureaucrat &executor);
};

#endif