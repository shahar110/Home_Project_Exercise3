#ifndef __VISITATION_EXCEPTION_H
#define __VISITATION_EXCEPTION_H

#include <iostream>
#include <string>
using namespace std;

class VisitationException
{
public:
	virtual void show() const
	{
		cout << "Failed to create Visit Form object!" << endl;
	}
};

class VisitationPurposeException : public VisitationException
{
private:
	string value;

public:
	VisitationPurposeException(const string& purpose) : value(purpose) {}

	virtual void show() const override
	{
		VisitationException::show();
		cout << "Invalid purpose value \"" << value << "\" entered!" << endl;
	}
};

class VisitationRoomException : public VisitationException
{
private:
	int value;

public:
	VisitationRoomException(int room) : value(room) {}

	virtual void show() const override
	{
		VisitationException::show();
		cout << "Invalid room value " << value << " entered!" << endl;
	}
};

#endif