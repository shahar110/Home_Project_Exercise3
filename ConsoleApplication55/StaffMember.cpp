#include "StaffMember.h"

int StaffMember::employeeNumCounter = 0;

StaffMember::StaffMember(const string& newName)
{
	employeeNumCounter++;
	employeeNum = employeeNumCounter;
	setName(newName);
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
