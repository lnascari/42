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
		this->grade = 1;
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
	name = b.name;
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

void Bureaucrat::signForm(AForm &f)
{
	const char *e = f.beSigned(*this);
	if (!e)
		std::cout << name << " signed " << f.getName() << std::endl;
	else
		std::cout << name << " couldn't sign " << f.getName() << " because " << e << std::endl;
}

void Bureaucrat::executeForm(AForm &f)
{
	const char *e = f.execute(*this);
	if (!e)
		std::cout << name << " executed " << f.getName() << std::endl;
	else
		std::cout << name << " couldn't sign " << f.getName() << " because " << e << std::endl;
}