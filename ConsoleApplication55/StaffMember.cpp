#include "StaffMember.h"

int StaffMember::employeeNumCounter = 0;

StaffMember::StaffMember(const string& newName)
{
	employeeNumCounter++;
	employeeNum = employeeNumCounter;
	setName(newName);
	depIndex = -1;

}

bool StaffMember::setName(const string& tmpName) throw (StaffMemberNameException)
{
	if (tmpName.length() > 20 || tmpName.empty())
		throw StaffMemberNameException(tmpName);

	this->name = tmpName;
	return true;
}

const string& StaffMember::getName() const
{
	return name;
}

int StaffMember::getEmployeeNum() const
{
	return employeeNum;
}
StaffMember::StaffMember(ifstream& in)
{
	char temp[10];
	in >> name;
}
void StaffMember::save(ofstream& out) const
{
	out << name;
}
void StaffMember::saveType(ofstream& outFile) const
{
	StaffGenerator::StaffType type = StaffGenerator::GetType(this);
	outFile << &type;
}