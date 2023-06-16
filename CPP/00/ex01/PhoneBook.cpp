#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	last = 0;
}

void PhoneBook::addContact()
{
	std::cout << std::endl;
	if (index < 8) {
		contacts[index++].fillContact();
	} else {
		contacts[last].fillContact();
		last = (last + 1) % 8;
	}
	std::cout << std::endl;
}

void PhoneBook::serchContact()
{
	std::string	num;

	std::cout << std::endl;
	if (!index)
		return;
	std::cout << std::setw(10) << "index";
	std::cout << " | " << std::setw(10) << "first name";
	std::cout << " | " << std::setw(10) << "last name";
	std::cout << " | " << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < index; i++) {
		contacts[i].displayContact(i);
	}
	std::cout << std::endl;
	while (1) {
		std::cout << "Insert an index: ";
		std::cin >> num;
		if (num.length() == 1 && std::isdigit(num[0]) && std::atoi(num.c_str()) < index) {
			contacts[std::atoi(num.c_str())].displayValues();
			break;
		}
		std::cout << "Index out of range" << std::endl;
	}
	std::cout << std::endl;
}