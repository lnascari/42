#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->N = N;
	i = 0;
}

Span::Span(const Span &s)
{
	*this = s;
}

Span &Span::operator=(const Span &s)
{
	v = s.v;
	N = s.N;
	i = s.i;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (i == N)
		throw ArrayFullException();
	v.push_back(n);
	i++;
}

void Span::addNumber(int count, int n)
{
	if (i + count >= N)
		throw ArrayFullException();
	v.insert(v.begin(), count, n);
}

int Span::shortestSpan()
{
	if (v.size() < 2)
		throw ArrayEmptyException();
	int span = 0;
	for (unsigned int i = 0; i < N - 1; i++)
	{
		if (!span || abs(v[i] - v[i + 1]) < span)
			span = abs(v[i] - v[i + 1]);
	}
	return span;
}

int Span::longestSpan()
{
	if (v.size() < 2)
		throw ArrayEmptyException();
	return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end());
}