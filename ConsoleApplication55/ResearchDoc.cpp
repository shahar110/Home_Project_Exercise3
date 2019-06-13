#include "ResearchDoc.h"



ResearchDoctor::ResearchDoctor(const string& name, const string& expertise) : Doctor(name, expertise), Researcher(name), StaffMember(name)
{
}
ResearchDoctor::ResearchDoctor(ifstream& in)
	: StaffMember(in), Doctor(in), Researcher(in)
{

}

void ResearchDoctor::save(ofstream& out) const
{
	Doctor::save(out);
}