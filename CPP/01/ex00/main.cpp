#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie *zombie = newZombie("giambattista");
	zombie->announce();
	randomChump("paolo");
	delete zombie;
}