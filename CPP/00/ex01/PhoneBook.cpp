#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	last = 0;
}

void PhoneBook::addContact()
{
	if (index < 8) {
		contacts[index++].fillContact();
	} else {
		contacts[last].fillContact();
		last = (last + 1) % 8;
	} 
}

void PhoneBook::serchContact()
{
	int	index;

	if (!this->index)
		return;
	std::cout << std::setw(10) << "index";
	std::cout << " | " << std::setw(10) << "first name";
	std::cout << " | " << std::setw(10) << "last name";
	std::cout << " | " << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < this->index; i++) {
		contacts[i].displayContact(i);
	}
	while (1) {
		std::cout << "Insert an index: ";
		std::cin >> index;
		if (index >= 0 && index < this->index) {
			contacts[index].displayContact(index);
			break;
		}
		std::cin.clear();
		std::cout << "Index out of range" << std::endl;
	}
}