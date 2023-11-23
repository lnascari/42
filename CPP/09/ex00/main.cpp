#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	try
	{
		BitcoinExchange b();
		std::ifstream f;
		f.open(argv[1]);
		if (!f)
			throw FileException();
		std::string str;
		std::getline(f, str);
		if (str != "date | value") {
			std::cerr << "Error: bad format" << std::endl;
			f.close();
			return 1;
		}
		while (std::getline(f, str)) {
			char *date(std::strtok((char *) str.c_str(), " | "));
			char *value = std::strtok(0, " | ");
			if (!date || !value) {
				std::cerr << "Error: bad input => " << str << std::endl;
				continue;
			}
			struct tm tm;
			if (date < "2009-01-02" || date > "2022-03-29" || !strptime(date, "%Y-%m-%d", &tm) || strptime(date, "%Y-%m-%d", &tm)[0]) {
				std::cerr << "Error: invalid date." << std::endl;
				continue;
			}
			std::stringstream s(value);
			double n;
			s >> n;
			if (s.fail() || !s.eof()) {
				std::cerr << "Error: invalid value." << std::endl;
				continue;
			}
			if (n < 0) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (n > 147483648) {
				std::cerr << "Error: too large number." << std::endl;
				continue;
			}
			std::cout << date << " => " << n << " = " << b.getValue(date, n) << std::endl;
		}
		f.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
}