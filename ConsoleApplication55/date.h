#ifndef __DATE_EXCEPTION_H
#define __DATE_EXCEPTION_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "DateException.h"
#include <fstream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
	
public:
	Date(int day, int month, int year);
	Date(ifstream &);
	bool setDay(int newDay);
	bool setMonth(int newMonth);
	bool setYear(int newYear);
	void save(ofstream &);
	void printDate() const;
	friend ostream& operator<<(ostream& os, const Date &d)
	{
		os <<d.day << "/" << d.month << "/" << d.year;
		return os;
	}
};

#endif