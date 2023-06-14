#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::string getValue(std::string field);
	std::string formattedValue(std::string value);
public:
	void fillContact();
	void displayContact(int index);
	void displayValues();
};

#endif