#ifndef ARRAY_HPP
#define ARRAY_HPP

class IndexOutOfBoundsException : public std::exception {
public:
	const char *what() const throw() {
		return "Index out of bounds";
	}
};

template <typename T> class Array
{
private:
	T *arr;
	unsigned int n;
public:
	Array()
	{
		arr = new T();
		n = 0;
	}
	Array(unsigned int n)
	{
		arr = new T[n];
		this->n = n;
	}
	Array(const Array &a)
	{
		*this = a;
	}
	Array &operator=(const Array &a)
	{
		if(this == &a)
			return *this;
		delete[] arr;
		arr = new T[a.n];
		n = a.n;
		for (size_t i = 0; i < a.n; i++)
			arr[i] = a.arr[i];
		return *this;
	}
	~Array()
	{
		delete[] arr;
	}
	T& operator[](unsigned int i){
		if (i >= n)
			throw IndexOutOfBoundsException();
		return arr[i];
	}
	unsigned int size()
	{
		return n;
	}
};

#endif
