#ifndef __RESEARCH_DOC_H
#define __RESEARCH_DOC_H

#include "doctor.h"
#include "researcher.h"
#include <string>

class ResearchDoctor : public Doctor, public Researcher
{
public:
	ResearchDoctor(const string& name, const string& expertise);

};

#endif;

