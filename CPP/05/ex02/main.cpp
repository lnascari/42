#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdio>

int main()
{
	Bureaucrat b("franco", 146);
	std::cout << b << std::endl;
	ShrubberyCreationForm s("sos");
	b.executeForm(s);
	b.signForm(s);
	b.increment();
	b.signForm(s);
	b.executeForm(s);
	std::cout << std::endl << s << std::endl;
	Bureaucrat b2("gigi", 5);
	std::cout  << b2 << std::endl;
	b2.executeForm(s);
	std::ifstream file("sos_shrubbery");
	std::string line;
	while (getline(file, line))
		std::cout << line << std::endl;
	file.close();
	std::remove("sos_shrubbery");
	RobotomyRequestForm r("pippo");
	b2.signForm(r);
	b2.executeForm(r);
	PresidentialPardonForm p("paolo");
	b2.signForm(p);
	b2.executeForm(p);
}