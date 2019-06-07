#include "Array.h"


template<class T>
Array<T>::Array(int maxSize) : physicalSize(maxSize), logicalSize(0)
{
	arr = new T[physicalSize];
}
template<class T>
Array<T>::Array(const Array& other) : arr(NULL)
{
	*this = other;
}

template<class T>
Array<T>::~Array()
{
	delete[]arr;
}

template<class T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[]arr;
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		arr = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template<class T>
const Array<T>& Array<T>::operator+=(const T&newVal)
{
	if (logicalSize < physicalSize)
	{
		arr[logicalSize++] = newVal;
	}
	return *this;
}

template<class T>
const int Array<T>::getSize()  const 
{
	return logicalSize;
}

