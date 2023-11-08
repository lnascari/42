#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &os, Bureaucrat &b)
{
	std::stringstream s;
	s << b.getGrade();
	os << b.getName() + ", bureaucrat grade " << s.str() << std::endl;
	return os;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	try {
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		this->grade = grade;
	}
	catch(const std::exception& e) {
		this->grade = 150;
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	*this = b;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	if(this == &b)
		return *this;
	grade = b.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()
{
	return name;
}

int Bureaucrat::getGrade()
{
	return grade;
}

void Bureaucrat::increment()
{
	try {
		if (grade <= 1)
			throw GradeTooHighException();
		grade--;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrement()
{
	try {
		if (grade >= 150)
			throw GradeTooLowException();
		grade++;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}