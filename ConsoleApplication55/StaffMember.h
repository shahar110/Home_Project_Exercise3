#ifndef __STAFF_MEMBER_H
#define __STAFF_MEMBER_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "StaffMemberException.h"
using namespace std;



class StaffMember
{
protected:
	string name;
	static int employeeNumCounter;
	int employeeNum;
public:
	StaffMember(const string& name);

	bool setName(const string& name);
	const string& getName() const;

	int getEmployeeNum() const;
};

#endif;