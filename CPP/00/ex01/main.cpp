#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string str;

	while (1){
		std::cout << "Insert a command: ";
		std::cin >> str;
		if (str == "ADD")
			phonebook.addContact();
		else if (str == "SEARCH")
			phonebook.serchContact();
		else if (str == "EXIT")
			break;
	}
}