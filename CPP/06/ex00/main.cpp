#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || std::string(argv[1]).empty())
		return 1;
	ScalarConverter::convert(std::string(argv[1]));
}