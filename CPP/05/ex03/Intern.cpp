#include "Intern.hpp"

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string s[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	for (size_t i = 0; i < 3; i++) {
		if (name == s[i]) {
			std::cout << "Intern creates " << name << std::endl;
			for (size_t j = 0; j < 3; j++) {
				if (i == j)
					continue;
				delete forms[j];
			}
			return forms[i];
		}
	}
	std::cout << name << " does not exist" << std::endl;
	for (size_t i = 0; i < 3; i++)
		delete forms[i];
	return 0;
}