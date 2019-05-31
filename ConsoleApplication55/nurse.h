#ifndef __NURSE_H
#define __NURSE_H
#include "StaffMember.h"
#include "NurseException.h"
using namespace std;

class Nurse : public StaffMember
{
private:
	int experience;

public:
	Nurse(string name, int experience);

	bool setExperience(int experience);

	int getExperience() const;

	void print() const;
	friend ostream& operator<<(ostream& os, const Nurse &nurse)
	{
		os << "Nurse name: " << nurse.name << "   , years of experience: " << nurse.experience
			<< "   , ID: " << nurse.employeeNum;
		return os;
	}
};

#endif