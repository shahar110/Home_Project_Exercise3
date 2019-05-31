#include "ResearchDoc.h"



ResearchDoctor::ResearchDoctor(const string& name, const string& expertise) : Doctor(name, expertise), Researcher(name), StaffMember(name)
{
}
