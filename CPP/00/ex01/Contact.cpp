#include "Contact.hpp"

std::string Contact::getValue(std::string field)
{
	std::string str;

	while (1) {
		std::cout << "Insert your " << field << ": ";
		std::getline(std::cin, str);
		if (!str.empty())
			break;
		std::cout << "Field is empty" << std::endl;
	}
	return str;
}

std::string Contact::formattedValue(std::string value)
{
	if (value.length() > 10)
		return value.substr(0, 9) + '.';
	return value;
}

void Contact::fillContact()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	firstName = getValue("first name");
	lastName = getValue("last name");
	nickname = getValue("nickname");
	phoneNumber = getValue("phone number");
	darkestSecret = getValue("darkest secret");
}

void Contact::displayContact(int index)
{
	std::cout << std::setw(10);
	std::cout << index << " | ";
	std::cout << std::setw(10);
	std::cout << formattedValue(firstName) << " | ";
	std::cout << std::setw(10);
	std::cout << formattedValue(lastName) << " | ";
	std::cout << std::setw(10);
	std::cout << formattedValue(nickname) << std::endl;
}

void Contact::displayValues()
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}