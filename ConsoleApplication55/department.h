#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#define _CRT_SECURE_NO_WARNINGS
#include "doctor.h"
#include "nurse.h"
#include "patient.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Department
{
private:
	string name;
	vector<Doctor*> allDoctors;
	vector<Nurse*> allNurses;
	vector<Patient*> allPatients;

	int numOfPatients = 0;
	int physPatientsArr = 2;

	int numOfDoctors = 0;

public:
	Department(const string& departmentName);
	Department(ifstream& in);
	~Department();

	bool setName(const string& departmentName);
	bool addDoctor(Doctor* newDoctor);
	bool addNurse(Nurse* newNurse);
	bool addPatient(Patient* newPatient);
	bool setNumOfPatients(int num);
	void setNumOfDoctors(int num);
	const string& getName() const { return name; };
	vector<Doctor*>& getAllDoctors();
	int getNumOfDoctors() const;
	vector<Nurse*> getAllNurses();
	int getNumOfNurses() const;
	vector<Patient*> getAllPatients();
	int getNumOfPatients() const;

	const string& selectStaffMember(int* staffMemberNum);

	void printDepartment() const;
	void printDepartmentStaff() const;
	void printPatientsList() const;
	bool operator+=(Doctor* newDoctor);
	bool operator+=(Nurse* newNurse);
	bool operator+=(Patient* newPatient);
	
	friend ostream& operator <<(ostream& out, const Department& department)
	{
		out << department.name;
		return out;
	}

	friend istream& operator >> (istream& in, Department& department)
	{
		char temp[128];
		in.getline(temp, 128);
		in >> department.name;
		return in;
	}
};

#endif