#include "StaffGenerator.h"

#include "StaffGenerator.h"
#include "Doctor.h"
#include "ResearchDoc.h"
#include "SurgeonDoc.h"

#include <assert.h>

StaffMember* StaffGenerator::LoadStaff(std::ifstream& in)
{
	StaffType type;
	in.read((char*)&type, sizeof(int));

	switch (type)
	{
	case DOCTOR:
		return new Doctor(in);
		break;
	case SURGEON:
		return new SurgeonDoctor(in);
		break;
	case REDOCTOR:
		return new ResearchDoctor(in);
		break;
	case UNKNOWN:
		break;
	}
	return nullptr;
}

StaffGenerator::StaffType StaffGenerator::GetType(const StaffMember* member)
{
	if (typeid(*member) == typeid(Doctor))
		return DOCTOR;
	else if (typeid(*member) == typeid(SurgeonDoctor))
		return SURGEON;
	else if (typeid(*member) == typeid(ResearchDoctor))
		return REDOCTOR;
	else
		return UNKNOWN;
}
