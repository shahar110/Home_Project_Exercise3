#define _CRT_SECURE_NO_WARNINGS
#include "doctor.h"

Doctor::Doctor(const string& name, const string& expertise) : StaffMember(name)
{
	setExpertise(expertise);
}

Doctor::Doctor(ifstream& inFile) : StaffMember(inFile)
{
	char temp[10];
	inFile >>expertise;
}

bool Doctor::setExpertise(const string& tmpExpertise) throw (DoctorExperException)
{
	if (tmpExpertise.length() > 20 || tmpExpertise.empty())
		throw DoctorExperException(tmpExpertise);

	this->expertise = tmpExpertise;
	return true;
}

const string& Doctor::getExpertise() const
{
	return expertise;
}

void Doctor::print() const
{
	cout << "Doctor name: " << name << " , field of expertise: " << expertise
		<< " , ID: " << employeeNum;
}

void Doctor::save(ofstream& out) const
{
	StaffMember::save(out);
	out << expertise;
}

void Doctor::printTemp() const
{
	cout << "Doctor name: " << name << " ,  Department Index: " << depIndex
		<< " and expertise: " << expertise;
}