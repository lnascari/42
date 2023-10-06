#include "Intern.hpp"

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string s[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *forms[4] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	for (size_t i = 0; i < 4; i++) {
		if (name == s[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return forms[i];
		}
	}
	std::cout << name << "does not exist" << std::endl;
	return 0;
}