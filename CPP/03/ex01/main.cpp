#include "ScavTrap.hpp"

int main ()
{
	ScavTrap s("Franco");
	s.guardGate();
	s.takeDamage(87);
	s.beRepaired(19);
	s.attack("Giovanni");
}