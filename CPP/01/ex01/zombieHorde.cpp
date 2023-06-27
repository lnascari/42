#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* arr = static_cast<Zombie*>(::operator new[](N*sizeof(Zombie)));
    for (size_t i = 0; i < N; i++)
        ::new (arr+i) Zombie(name);
    return arr;
}