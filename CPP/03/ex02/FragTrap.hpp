#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{	
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	FragTrap &operator=(const FragTrap &f);
	~FragTrap();
	void attack(const std::string& target);
	void highFivesGuys();
};

#endif