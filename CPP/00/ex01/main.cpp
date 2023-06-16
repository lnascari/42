#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string str = "";

	while (str != "EXIT"){
		std::cout << "Insert a command: ";
		std::cin >> str;
		if (str == "ADD")
			phonebook.addContact();
		else if (str == "SEARCH")
			phonebook.serchContact();
		else if (str != "EXIT")
			std::cout << "Invalid command" << std::endl << std::endl;
	}
}