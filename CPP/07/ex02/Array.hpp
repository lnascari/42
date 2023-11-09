#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array
{
private:
	T *arr;
	unsigned int n;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &a);
	Array &operator=(const Array &a);
	~Array();
	T& operator[](int i);
	unsigned int size();
};

#endif

template <typename T>
inline Array<T>::Array()
{
}

template <typename T>
inline Array<T>::Array(unsigned int n)
{
}

template <typename T>
inline Array<T>::Array(const Array &a)
{
}

template <typename T>
inline Array &Array<T>::operator=(const Array &a)
{
	// TODO: insert return statement here
}

template <typename T>
inline Array<T>::~Array()
{
}

template <typename T>
inline T &Array<T>::operator[](int i)
{
	// TODO: insert return statement here
}

template <typename T>
inline unsigned int Array<T>::size()
{
	return 0;
}
