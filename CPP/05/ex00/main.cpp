#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("franco", 170);
	b.decrement();
	std::cout << b;
	for (size_t i = 0; i < 150; i++)
		b.increment();
	std::cout << b;
	Bureaucrat b2("paolo", 7);
	std::cout << b2;
	for (size_t i = 0; i < 10; i++)
		b2.increment();
	std::cout << b2;
}