#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <cmath>

class ArrayFullException : public std::exception {
public:
	const char *what() const throw() {
		return "Array is full";
	}
};

class ArrayEmptyException : public std::exception {
public:
	const char *what() const throw() {
		return "Array is empty";
	}
};

class Span
{
private:
	std::vector<int> v;
	unsigned int N;
	unsigned int i;
public:
	Span(unsigned int N);
	Span(const Span &s);
	Span &operator=(const Span &s);
	~Span();
	void addNumber(int n);
	void addNumber(int first, int last);
	int shortestSpan();
	int longestSpan();
};

#endif