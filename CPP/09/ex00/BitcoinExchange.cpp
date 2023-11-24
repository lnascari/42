#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream f;
	f.open("data.csv");
	if (!f)
		throw FileException();
	f.close();
	std::string str;
	std::getline(f, str);
	while (std::getline(f, str)) {
		char * date(std::strtok((char *) str.c_str(), ","));
		std::stringstream s(std::strtok(0, ","));
		double n;
		s >> n;
		db[date] = n;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b)
{
	*this = b;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &b)
{
	if (this == &b)
		return *this;
	db = b.db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getValue(std::string date, double n)
{
	(void) date;
	(void) n;
	return 0.0;
}