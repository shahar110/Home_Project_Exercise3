#ifndef __STAFF_GENERATOR
#define __STAFF_GENERATOR

#include <fstream>
#include <vector>

class StaffMember;
class Department;

class StaffGenerator
{
public:
	enum StaffType
	{
		UNKNOWN = 0, DOCTOR, NURSE, SURGEON,
		REDOCTOR, RESURGEON
	};

	static StaffMember* LoadStaff(std::ifstream&);
	static StaffType GetType(const StaffMember*);
};

#endif //__STAFF_GENERATOR