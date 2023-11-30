#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> v;
	std::deque<int> d;
	template <typename T> void insertionSort(T &arr, int begin, int end)
	{
		for (int i = begin; i < end; i++) {
			for (int j = i; j > begin && arr[j - 1] > arr[j]; j--) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	template <typename T> void merge(T &a, T &b, int begin, int middle, int end)
	{
		for (int i = begin, j = middle, k = begin; k < end; k++) {
			if (i < middle && (j >= end || a[i] <= a[j]))
				b[k] = a[i++];
			else
				b[k] = a[j++];
		}
	}
	template <typename T> void mergeSort(T &a, int begin, int end)
	{
		if (end - begin <= 5)
			insertionSort(a, begin, end);
		else {
			int middle = (begin + end) / 2;
			mergeSort(a, begin, middle);
			mergeSort(a, middle, end);
			T b = a;
			merge(a, b, begin, middle, end);
			a = b;
		}
	}
public:
	PmergeMe();
	PmergeMe(int arr[], int size);
	PmergeMe(const PmergeMe &p);
	PmergeMe &operator=(const PmergeMe &p);
	~PmergeMe();
	void sort();
};

#endif