#ifndef ITER_HPP
#define ITER_HPP

template <typename T> void toupper(T &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

template <typename T, typename A> void iter(T *arr, size_t len, void (*f)(A &el))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

#endif