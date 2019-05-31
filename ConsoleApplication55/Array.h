#ifndef __ARRAY_H
#define __ARRAY_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<class T>
class Array
{
	int physicalSize, logicalSize;
	char delimiter;
	T* arr;
public:
	Array(int size = 10, char delimiter = ' ');
	Array(const Array& other);
	~Array();
	
    const int getSize()	 const;
	const Array& operator=(const Array& other);
	const Array& operator+=(const T& newVal);

	friend ostream& operator<<(ostream& os, const Array& arr) 
	{
		for (int i = 0; i < arr.logicalSize; i++)
			os << arr.arr[i] << arr.delimiter;
		return os;
	}
};

#endif;