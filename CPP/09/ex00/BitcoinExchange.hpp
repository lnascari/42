#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>

class FileException : public std::exception {
public:
	const char *what() const throw() {
		return "Can't open file";
	}
};

class BitcoinExchange
{
private:
	std::map<std::string, double> db;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &b);
	BitcoinExchange &operator=(const BitcoinExchange &b);
	~BitcoinExchange();
};

#endif