#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	try
	{
		std::ifstream f;
		f.open(argv[1]);
		if (!f)
			throw FileException();
		std::string str;
		std::getline(f, str);
		if (str != "date | value") {
			std::cerr << "Error: bad format" << std::endl;
			f.close();
		}
		while (std::getline(f, str)) {
			std::cout << str << std::endl;
		}
		
		f.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}