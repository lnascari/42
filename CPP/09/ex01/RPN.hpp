#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN
{
private:
	std::stack<int> stack;
public:
	RPN();
	RPN(const RPN &r);
	RPN &operator=(const RPN &r);
	~RPN();
};

#endif