#include "RPN.hpp"
#include <sstream>
#include <vector>
#include <cctype>

int main(int argc, char const *argv[])
{
	if (argc != 2)
		exit((std::cout << "Error" << std::endl, 1));
	RPN rpn;
	std::stringstream ss(argv[1]);
	std::string str;
	while (getline(ss, str, ' ')) {
		if (str.empty())
			continue;
		if (str.size() != 1)
			exit((std::cout << "Error" << std::endl, 1));
		if (isdigit(str[0])) {
			rpn.push(str[0] - 48);
			continue;
		}
		switch (str[0]) {
		case '+':
			rpn.addition();
			break;
		case '-':
			rpn.subtraction();
			break;
		case '*':
			rpn.multiplication();
			break;
		case '/':
			rpn.division();
			break;
		default:
			exit((std::cout << "Error" << std::endl, 1));
		}
    }
	std::cout << rpn.top() << std::endl;
}