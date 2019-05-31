#ifndef __VISITATION_FORM_H
#define __VISITATION_FORM_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "date.h"
#include "VisitationException.h"
using namespace std;

const int CHECK = 1;
//enum ePurpose { Treatment, Medicine ,Emergency, Visit, Reception };
//namespace { const char* visitPurpose[] = { "Treatment", "Medicine", "Emergency", "Visit", "Reception" }; }

class VisitForm
{
protected:
	Date arrivalDate;
	int purpose;   

	string therapistName;
	int therapistNum;	

	string departmentName;
	int departmentPatientIndex = -1;

public:
	VisitForm(const Date& date, int purpose, int therapistNum, const string& therapistName,  const string& departmentName);

	bool setDate(const Date& newDate);
	bool setPurpose(int newPurpose);
	bool setTherapist(int therapistNum, const string& therapistName);
	bool setDepartmentName(const string& newDepartment);
	bool setDepartmentIndex(int index);

	Date getDate() const;
	int getPurpose() const;
	int getTherapist() const;
	const string& getDepartment() const;

	virtual void printVisitForm();
};

#endif