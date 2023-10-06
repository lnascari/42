#include "AForm.hpp"

std::ostream &operator<<(std::ostream &os, AForm &f)
{
	os << f.getName() << (f.getSigned() ? ", signed" : ", not signed") << ", sign grade ";
	os << f.getSign();
	os << ", execute grade ";
	os << f.getExecute();
	os << std::endl;
	return os;
}

AForm::AForm(const std::string name, const int sign, const int execute) : name(name), sign(sign), executed(execute)
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

AForm::AForm(const AForm &f) : sign(f.sign), executed(f.executed)
{
	*this = f;
}

AForm &AForm::operator=(const AForm &f)
{
	if(this == &f)
		return *this;
	isSigned = f.isSigned;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSigned()
{
	return isSigned;
}

int AForm::getSign() const
{
	return sign;
}

int AForm::getExecute() const
{
	return executed;
}

const char *AForm::beSigned(Bureaucrat &b)
{
	if (isSigned)
		return 0;
	try {
		if (b.getGrade() > sign)
			throw GradeTooLowException();
		this->isSigned = true;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		return e.what();
	}
	return 0;
}