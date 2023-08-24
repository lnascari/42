#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &b);
	Brain &operator=(const Brain &b);
	~Brain();
	void setIdea(std::string idea, int index);
	std::string getIdea(int index);
};

#endif