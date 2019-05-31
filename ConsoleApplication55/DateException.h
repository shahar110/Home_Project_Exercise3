#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include <string>
using namespace std;

class DateException
{
public:
	virtual void show() const
	{
		cout << "Failed to create Date object!" << endl;
	}
};

class DateDayException : public DateException
{
private:
	int value;

public:
	DateDayException(int day) : value(day) {}

	virtual void show() const override
	{
		DateException::show();
		cout << "Invalid day value " << value << " entered!" << endl;
	}
};

class DateMonthException : public DateException
{
private:
	int value;

public:
	DateMonthException(int month) : value(month) {}

	virtual void show() const override
	{
		DateException::show();
		cout << "Invalid month value " << value << " entered!" << endl;
	}
};

class DateYearException : public DateException
{
private:
	int value;

public:
	DateYearException(int year) : value(year) {}

	virtual void show() const override
	{
		DateException::show();
		cout << "Invalid year value " << value << " entered!" << endl;
	}
};
#endif