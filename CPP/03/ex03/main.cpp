#include "DiamondTrap.hpp"

int main ()
{
	DiamondTrap d("Pippo");
	d.whoAmI();
	d.beRepaired(2);
	d.guardGate();
	d.attack("Giambattista");
	d.takeDamage(50);
	d.attack("Gigi");
}