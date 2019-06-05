#ifndef __PATIENT_H
#define __PATIENT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#include "VisitationForm.h"
#include "surgeryVisitation.h"
#include "PatientException.h"
#include <vector>
enum eGender {Male, Female};
namespace { const char* genders[] = { "Male", "Female" }; }

class Patient
{
private:
	string name;
	int id;
	int birthYear;
	eGender gender;
	vector<VisitForm*> visitsArr;


	int visitHistoryCounter = 0;
	int physVisitArr = 2;

	int departmentIndex = -1;
	int departmentPatientArrIndex = -1;

public:
	Patient(const string& name, int id, int birthYear, eGender gender);

	bool setName(const string& newName);
	bool setId(long newId);
	bool setBirthYear(int newBirthYear);
	bool setGender(eGender newGender);
	bool addVisit(const Date& arrivalDate,int purpose, int therapistNum, const string& therapistName, const string& departmentName);
	bool setDepartmentIndex(int index);
	bool setDepartmentPatientArrIndex(int index);

	const string& getName() const { return name; };
	int getId() const;
	int getBirthYear() const;
	eGender getGender() const;
	vector<VisitForm*> getVisitsArr() const;
	int getDepartmentPatientArrIndex() const;
	int getDepartmentIndex() const;
	int getVisitCounter() const;

	void printPatient();
	void printCurrentVisit();
};

#endif