#include "DiamondTrap.hpp"

int main ()
{
	DiamondTrap d("Pippo");
	d.whoAmI();
	d.beRepaired(2);
	d.guardGate();
	d.attack("Giambattista");
	d.takeDamage(100);
	d.attack("Gigi");
	d.takeDamage(2);
	d.beRepaired(3000);
}