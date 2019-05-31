#ifndef __DOCTOR_H
#define __DOCTOR_H
#include "StaffMember.h"
#include "DoctorException.h"
#include <string>


class Doctor : virtual public StaffMember
{
protected:
	string expertise;

public:
	Doctor(const string& name, const string& expertise);

	bool setExpertise(const string& expertise);

	const string& getExpertise() const;

	virtual void print() const;
};

#endif