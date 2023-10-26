#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	if (str == "+inff" || str == "+inf") {
		;
	} else if (str == "-inff" || str == "-inf") {
		;
	} else if (str.length() == 1 && !std::isdigit(str[0])) {
		printConv(str[0], static_cast<int>(str[0]), static_cast<float>(str[0]), static_cast<double>(str[0]));
	} else if (isInt(str)) {
		std::stringstream s(str);
		int n;
		s >> n;
		printConv(static_cast<char>(n), n, static_cast<float>(n), static_cast<double>(n));
	} else if (str[str.length() - 1] == 'f' && isFloat(str.substr(0, str.length() - 1))) {
		std::stringstream s(str);
		float f;
		s >> f;
		printConv(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
	} else if (isDouble(str)) {
		std::stringstream s(str);
		double d;
		s >> d;
		printConv(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
	} else
}

bool ScalarConverter::isInt(std::string str)
{
	std::stringstream s(str);
	int n;
	s >> n;
	return !s.fail();
}

bool ScalarConverter::isFloat(std::string str)
{
	std::stringstream s(str);
	float f;
	s >> f;
	return !s.fail();
}

bool ScalarConverter::isDouble(std::string str)
{
	std::stringstream s(str);
	double d;
	s >> d;
	return !s.fail();
}