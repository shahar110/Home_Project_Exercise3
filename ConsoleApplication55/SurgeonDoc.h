#ifndef __SURGEON_DOC_H
#define __SURGEON_DOC_H

#include "doctor.h"
#include "DoctorException.h"

class SurgeonDoctor : public Doctor
{
protected:
	int numOfSurgeries;
public:
	SurgeonDoctor(const string& name, const string& expetise, int numOfSurgeries);

	bool setNumOfSurgeries(int numOfSurgeries);

	int getNumOfSurgeries() const;

	void print() const;
};

#endif;