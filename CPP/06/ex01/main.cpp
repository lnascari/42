#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data *d = new Data();
	d->data = 42;
	uintptr_t p = Serializer::serialize(d);
	std::cout << d << std::endl;
	std::cout << p << std::endl;
	std::cout << Serializer::deserialize(p) << std::endl;
	delete d;
}