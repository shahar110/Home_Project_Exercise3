#ifndef __DOCTOR_H
#define __DOCTOR_H
#include "StaffMember.h"
#include "DoctorException.h"
#include <string>
#include <fstream>
using namespace std;

class Doctor : virtual public StaffMember
{
protected:
	string expertise;

public:
	Doctor(const string& name, const string& expertise);
	Doctor(ifstream& inFile);
	bool setExpertise(const string& expertise);
	void save(ofstream&) const override;
	const string& getExpertise() const;
	void printTemp() const;
	virtual void print() const;

	//friend istream& operator >> (istream& in, Doctor &doctor)
	//{
	//	char delimiter;
	//	in >> (StaffMember&)doctor;
	//	in >> expertise;
	//}

};

#endif