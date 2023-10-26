#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

class ScalarConverter
{
private:
	static bool isInt(std::string str);
	static bool isFloat(std::string str);
	static bool isDouble(std::string str);
	static void printConv(char c, int n, float f, double d);
public:
	static void convert(std::string str);
};

#endif