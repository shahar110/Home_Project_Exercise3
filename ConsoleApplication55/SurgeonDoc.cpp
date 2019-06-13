#include "SurgeonDoc.h"

SurgeonDoctor::SurgeonDoctor(const string& name, const string& expetise, int numOfSurgeries) : Doctor(name, expetise), StaffMember(name)
{
	setNumOfSurgeries(numOfSurgeries);
}

SurgeonDoctor::SurgeonDoctor(ifstream& in) : StaffMember(in), Doctor(in)
{
	in >> numOfSurgeries;
}
bool SurgeonDoctor::setNumOfSurgeries(int numOfSurgeries) throw (DoctorSurgeriesException)
{
	if (numOfSurgeries < 0 || numOfSurgeries > 2000)
		throw DoctorSurgeriesException(numOfSurgeries);

	this->numOfSurgeries = numOfSurgeries;
	return true;
}


int SurgeonDoctor::getNumOfSurgeries() const
{
	return numOfSurgeries;
}

void SurgeonDoctor::print() const
{
	Doctor::print();
	cout << "     , number of performed surgeries: " << numOfSurgeries;
}

void SurgeonDoctor::save(ofstream& out) const
{
	Doctor::save(out);
	out << numOfSurgeries;
}
