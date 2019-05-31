#include "VisitationForm.h"

VisitForm::VisitForm(const Date& date, int purpose, int therapistNum, const string& therapistName, const string& departmentName) : arrivalDate(date)
{
	setPurpose(purpose);
	setTherapist(therapistNum, therapistName);
	setDepartmentName(departmentName);
}

bool VisitForm::setDate(const Date& newDate)
{
	arrivalDate = newDate;
	return true;
}

bool VisitForm::setPurpose(int newPurpose)
{
	purpose = newPurpose;
	return true;
}

bool VisitForm::setTherapist(int newNum, const string& newName)
{
	this->therapistName = newName;
	therapistNum = newNum;
	return true;
}

bool VisitForm::setDepartmentName(const string& newDepartment)
{
	this->departmentName = newDepartment;
	return true;
}

bool VisitForm::setDepartmentIndex(int index)
{
	departmentPatientIndex = index;
	return true;
}
Date VisitForm::getDate() const
{
	return arrivalDate;
}

int VisitForm::getPurpose() const
{
	return purpose;
}

int VisitForm::getTherapist() const
{
	return therapistNum;
}

const string& VisitForm::getDepartment() const
{
	return departmentName;
}

void VisitForm::printVisitForm()
{
	cout << "Department: " << departmentName << "    , Arrival Date: ";
	cout << arrivalDate; 
	cout << "   , Visit Purpose: " << purpose << "   , Assigned Therapist: " << therapistName;  
}


// checking changing 