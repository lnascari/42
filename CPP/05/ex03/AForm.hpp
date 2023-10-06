#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int sign;
	const int executed;
public:
	AForm(const std::string name, const int sign, const int execute);
	AForm(const AForm &f);
	AForm &operator=(const AForm &f);
	virtual ~AForm();
	std::string getName() const;
	bool getSigned();
	int getSign() const;
	int getExecute() const;
	const char *beSigned(Bureaucrat &b);
	virtual const char *execute(Bureaucrat &executor) = 0;
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
	class FormNotSignedException : public std::exception {
	public:
		const char *what() const throw() {
			return "Form not signed";
		}
	};
};

std::ostream &operator<<(std::ostream &os, AForm &f);

#endif