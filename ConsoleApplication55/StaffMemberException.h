#ifndef __STAFF_MEMBER_EXCEPTION_H
#define __STAFF_MEMBER_EXCEPTION_H

#include <iostream>
#include <string>
using namespace std;

class StaffMemberException
{
public:
	virtual void show() const
	{
		cout << "Failed to create Staff Member object!" << endl;
	}
};

class StaffMemberNameException : public StaffMemberException
{
private:
	string value;

public:
	StaffMemberNameException(const string& st) : value(st) {}

	virtual void show() const override
	{
		StaffMemberException::show();
		cout << "Invalid name value \"" << value << " entered!" << endl;
	}
};

#endif