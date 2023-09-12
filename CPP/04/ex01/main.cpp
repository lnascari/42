#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal* arr[6];
	for (size_t i = 0; i < 6; i++) {
		if (i % 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}
	for (size_t i = 0; i < 6; i++)
		arr[i]->printIdea(i);
	for (size_t i = 0; i < 6; i++)
		delete arr[i];
}