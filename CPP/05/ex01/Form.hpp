#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int sign;
	const int execute;
public:
	Form(const std::string name, const int sign, const int execute);
	Form(const Form &f);
	Form &operator=(const Form &f);
	~Form();
	const std::string getName();
	bool getSigned();
	const int getSign();
	const int getExecute();
	const char *beSigned(Bureaucrat &b);
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too high";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too low";
		}
	};
};

std::ostream &operator<<(std::ostream &os, Form &f);

#endif