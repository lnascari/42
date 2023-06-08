#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << char(std::toupper(argv[i][j]));
	}
	std::cout << "\n";
	return 0;
}