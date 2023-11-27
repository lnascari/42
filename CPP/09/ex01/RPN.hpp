#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <cstdlib>
#include <iostream>

class RPN
{
private:
	std::stack<int> stack;
public:
	RPN();
	RPN(const RPN &r);
	RPN &operator=(const RPN &r);
	~RPN();
	void push(int n);
	int top();
	void addition();
	void subtraction();
	void multiplication();
	void division();
};

#endif