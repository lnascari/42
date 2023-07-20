#include "ClapTrap.hpp"

int main ()
{
	ClapTrap c("Orazio");
	c.attack("Paolo");
	c.takeDamage(9);
	c.beRepaired(200);
	c.takeDamage(200);
	c.takeDamage(1);
	c.beRepaired(10);
}