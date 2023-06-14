#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int index;
	int last;
public:
	PhoneBook();
	void addContact();
	void serchContact();
};

#endif