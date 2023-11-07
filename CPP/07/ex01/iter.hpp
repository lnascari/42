#ifndef ITER_HPP
#define ITER_HPP

template <typename T> void iter(T *arr, size_t len, void (*f)(T &el))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

#endif