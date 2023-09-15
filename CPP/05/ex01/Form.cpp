#include "Form.hpp"

std::ostream &operator<<(std::ostream &os, Form &f)
{
	os << f.getName() << (f.getSigned() ? ", signed" : ", not signed") << ", sign grade ";
	os << f.getSign();
	os << ", execute grade ";
	os << f.getExecute();
	os << std::endl;
}

Form::Form(const std::string name, const int sign, const int execute) : name(name), sign(sign), execute(execute)
{
	try {
		if (sign < 1 || execute < 1)
			throw GradeTooHighException();
		if (sign > 150 || execute > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Form::Form(const Form &f) : name(name), sign(sign), execute(execute)
{
	*this = f;
}

Form &Form::operator=(const Form &f)
{
	if(this == &f)
		return *this;
	isSigned = f.isSigned;
	return *this;
}

Form::~Form() {}

const std::string Form::getName()
{
	return name;
}

bool Form::getSigned()
{
	return isSigned;
}

const int Form::getSign()
{
	return sign;
}

const int Form::getExecute()
{
	return execute;
}

const char *Form::beSigned(Bureaucrat &b)
{
	if (isSigned)
		return 0;
	try {
		if (b.getGrade() > sign)
			throw GradeTooLowException();
		isSigned = true;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		return e.what();
	}
	return 0;
}