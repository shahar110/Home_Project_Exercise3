#ifndef __STAFF_MEMBER_H
#define __STAFF_MEMBER_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include "StaffMemberException.h"
#include "StaffGenerator.h"
using namespace std;



class StaffMember
{
protected:
	string name;
	static int employeeNumCounter;
	int employeeNum;
	int depIndex;
public:
	StaffMember() { ; }
	StaffMember(const string& name);

	bool setName(const string& name);
	const string& getName() const;
	StaffMember(ifstream& in);
	int getEmployeeNum() const;
	bool setIndex(int index) { depIndex = index; return true; }
	int getIndex() const { return depIndex; }
	friend ostream& operator <<(ostream& out, const StaffMember& staffMember)
	{
		out << staffMember.name;
		return out;
	}
	friend istream& operator >> (istream& in, StaffMember& staffMember)
	{
		in >> staffMember.name;
		return in;
	}
	virtual void save(ofstream&) const;
	void saveType(ofstream& outFile) const;
};

#endif;
