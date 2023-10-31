#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	if (str == "+inff" || str == "+inf") {
		printConv(0, 0, 0, 0, 1, 0);
	} else if (str == "-inff" || str == "-inf") {
		printConv(0, 0, 0, 0, 0, 1);
	} else if (str.length() == 1 && !std::isdigit(str[0])) {
		printConv(str[0], static_cast<int>(str[0]), static_cast<float>(str[0]), static_cast<double>(str[0]), 0, 0);
	} else if (isInt(str)) {
		std::stringstream s(str);
		int n;
		s >> n;
		printConv(static_cast<char>(n), n, static_cast<float>(n), static_cast<double>(n), 0, 0);
	} else if (str[str.length() - 1] == 'f' && isFloat(str.substr(0, str.length() - 1))) {
		std::stringstream s(str);
		float f;
		s >> f;
		printConv(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f), 0, 0);
	} else if (isDouble(str)) {
		std::stringstream s(str);
		double d;
		s >> d;
		printConv(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d, 0, 0);
	} else {
		printConv(0, 0, 0, 0, 1, 1);
	}
}

bool ScalarConverter::isInt(std::string str)
{
	std::stringstream s(str);
	int n;
	s >> n;
	return !s.fail() && s.eof();
}

bool ScalarConverter::isFloat(std::string str)
{
	std::stringstream s(str);
	float f;
	s >> f;
	return !s.fail() && s.eof();
}

bool ScalarConverter::isDouble(std::string str)
{
	std::stringstream s(str);
	double d;
	s >> d;
	return !s.fail() && s.eof();
}

void ScalarConverter::printConv(char c, int n, float f, double d, bool pinf, bool minf)
{
	std::cout << "char: ";
	if (pinf || minf)
		std::cout << "Impossible" << std::endl;
	else if (c == 127 || (c >= 0 && c <= 31))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << ((d > 127 || d < 0) ? "Overflow" : (std::string("'")+c)+"'") << std::endl;
	std::cout << "int: ";
	if (pinf || minf)
		std::cout << "Impossible" << std::endl;
	else if (d > INT_MAX || d < INT_MIN)
		std::cout << "Overflow" << std::endl;
	else
		std::cout << n << std::endl;
	std::cout << "float: ";
	if (pinf && minf)
		std::cout << "nanf" << std::endl;
	else if (pinf || minf)
		std::cout << (pinf ? "+inff" : "-inff") << std::endl;
	else if (d > FLT_MAX || d < FLT_MIN)
		std::cout << "Overflow" << std::endl;
	else
		std::cout << f << std::endl;
	std::cout << "double: ";
	if (pinf && minf)
		std::cout << "nan" << std::endl;
	else if (pinf || minf)
		std::cout << (pinf ? "+inf" : "-inf") << std::endl;
	else if (d > DBL_MAX || d < DBL_MIN)
		std::cout << "Overflow" << std::endl;
	else
		std::cout << d << std::endl;
}