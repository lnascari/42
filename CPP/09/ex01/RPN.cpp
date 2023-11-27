#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &r)
{
	*this = r;
}

RPN &RPN::operator=(const RPN &r)
{
	if (this == &r)
		return *this;
	stack = r.stack;
	return *this;
}

RPN::~RPN() {}

void RPN::push(int n)
{
	stack.push(n);
}

int RPN::top()
{
	return stack.top();
}

void RPN::addition()
{
	if (stack.size() < 2)
		exit((std::cout << "Error" << std::endl, 1));
	int x = stack.top();
	stack.pop();
	int y = stack.top();
	stack.pop();
	stack.push(y + x);
}

void RPN::subtraction()
{
	if (stack.size() < 2)
		exit((std::cout << "Error" << std::endl, 1));
	int x = stack.top();
	stack.pop();
	int y = stack.top();
	stack.pop();
	stack.push(y - x);
}

void RPN::multiplication()
{
	if (stack.size() < 2)
		exit((std::cout << "Error" << std::endl, 1));
	int x = stack.top();
	stack.pop();
	int y = stack.top();
	stack.pop();
	stack.push(y * x);
}

void RPN::division()
{
	if (stack.size() < 2)
		exit((std::cout << "Error" << std::endl, 1));
	int x = stack.top();
	stack.pop();
	int y = stack.top();
	stack.pop();
	stack.push(y / x);
}