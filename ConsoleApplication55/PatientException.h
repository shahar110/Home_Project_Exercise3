#ifndef __PATIENT_EXCEPTION_H
#define __PATIENT_EXCEPTION_H

#include <iostream>
#include <string>
using namespace std;

class PatientException
{
public:
	virtual void show() const
	{
		cout << "Failed to create Patient object!" << endl;
	}
};

class PatientNameException : public PatientException
{
private:
	string value;

public:
	PatientNameException(const string& name) : value(name) {}

	virtual void show() const override
	{
		PatientException::show();
		cout << "Invalid name value \"" << value << "\" entered!" << endl;
	}
};

class PatientIdException : public PatientException
{
private:
	int value;

public:
	PatientIdException(int id) : value(id) {}

	virtual void show() const override
	{
		PatientException::show();
		cout << "Invalid ID value " << value << " entered!" << endl;
	}
};

class PatientYearException : public PatientException
{
private:
	int value;

public:
	PatientYearException(int year) : value(year) {}

	virtual void show() const override
	{
		PatientException::show();
		cout << "Invalid year value " << value << " entered!" << endl;
	}
};

#endif