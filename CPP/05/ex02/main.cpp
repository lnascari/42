#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b("franco", 26);
	std::cout << b << std::endl;
	PresidentialPardonForm p("sos");
	b.executeForm(p);
	b.signForm(p);
	b.increment();
	b.signForm(p);
	b.executeForm(p);
	std::cout << std::endl << p << std::endl;
	Bureaucrat b2("gigi", 5);
	b2.executeForm(p);
	std::cout << std::endl << b2 << std::endl;
}