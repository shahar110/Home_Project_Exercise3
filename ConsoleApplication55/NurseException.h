#ifndef __NURSE_EXCEPTION_H
#define __NURSE_EXCEPTION_H

#include <iostream>
using namespace std;

class NurseException
{
public:
	virtual void show() const
	{
		cout << "Failed to create Nurse object!" << endl;
	}
};

class NurseExperException : public NurseException
{
private:
	int value;

public:
	NurseExperException(int val) : value(val) {}

	virtual void show() const override
	{
		NurseException::show();
		cout << "Invalid experience value " << value << " entered!" << endl;
	}
};

#endif