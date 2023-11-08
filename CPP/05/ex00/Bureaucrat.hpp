#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <sstream>
#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &b);
	Bureaucrat &operator=(const Bureaucrat &b);
	~Bureaucrat();
	std::string getName();
	int getGrade();
	void increment();
	void decrement();
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

std::ostream &operator<<(std::ostream &os, Bureaucrat &b);

#endif