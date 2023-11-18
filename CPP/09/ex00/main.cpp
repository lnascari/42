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
		f.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}