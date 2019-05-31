#ifndef __DOCTOR_EXCEPTION_H
#define __DOCTOR_EXCEPTION_H

#include <iostream>
#include <string>
using namespace std;

class DoctorException
{
public:
	virtual void show() const
	{
		cout << "Failed to create Doctor object!" << endl;
	}
};

class DoctorExperException : public DoctorException
{
private:
	string value;

public:
	DoctorExperException(const string& expertise) : value(expertise) {}

	virtual void show() const override
	{
		DoctorException::show();
		cout << "Invalid expertise value \"" << value << "\" entered!" << endl;
	}
};

class DoctorSurgeriesException : public DoctorException
{
private:
	int value;

public:
	DoctorSurgeriesException(int numOfSurgeries) : value(numOfSurgeries) {}

	virtual void show() const override
	{
		DoctorException::show();
		cout << "Invalid num of surgeries value " << value << " entered!" << endl;
	}
};

#endif