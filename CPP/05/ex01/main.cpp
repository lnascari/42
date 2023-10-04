#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("franco", 82);
	b.increment();
	std::cout << b;
	Form f("gigi", 80, 80);
	std::cout << f;
	b.signForm(f);
	b.increment();
	b.signForm(f);
	std::cout << f;
	std::cout << b;
}