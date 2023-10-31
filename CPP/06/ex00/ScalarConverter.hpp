#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <climits>
#include <cfloat>

class ScalarConverter
{
private:
	static bool isInt(std::string str);
	static bool isFloat(std::string str);
	static bool isDouble(std::string str);
	static void printConv(char c, int n, float f, double d, bool pinf, bool minf);
public:
	static void convert(std::string str);
};

#endif