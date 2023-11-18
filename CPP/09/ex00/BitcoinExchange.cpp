#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream f;
	f.open("data.csv");
	if (!f)
		throw FileException();
	f.close();
	
}

BitcoinExchange::~BitcoinExchange() {}
