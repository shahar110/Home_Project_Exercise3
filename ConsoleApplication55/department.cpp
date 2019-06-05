#include "department.h"

using namespace std;

// checking if there is max nurse and doc if not take care on the allocation
Department::Department(const string& departmentName)
{
	setName(departmentName);
}


Department::~Department()
{
	//delete[]allPatients;
}

bool Department::setName(const string& departmentName)
{
	name = departmentName;
	return true;
}

bool Department::addNurse(Nurse* newNurse)
{
	allNurses.push_back(newNurse);
	return true;
}

bool Department::addDoctor(Doctor* newDoctor)
{
	allDoctors.push_back(newDoctor);
	return true;
}

bool Department::addPatient(Patient* newPatient)
{
	allPatients.push_back(newPatient);
	//Save the array index for the patient (for later use)
	allPatients[numOfPatients]->setDepartmentPatientArrIndex(numOfPatients);
	numOfPatients++;
	return true;
}

const string& Department::selectStaffMember(int* staffMemberNum)
{
	int i,  selectionIndex = 0, selection;
	string staffMemberName;

	cout << "1: Doctors list" << endl;
	cout << "2: Nurses list" << endl;
	cin >> selection;

	switch (selection)
	{
	case 1:
		for (i = 0; i < allDoctors.size(); i++)
			cout << i << ":  Doctor " << allDoctors[i]->getName() << endl;

		cin >> selectionIndex;

		if (selectionIndex < 0 || selectionIndex > i - 1)
		{
			cout << "Ileggal selection entered!\nExiting...\n";
			return nullptr;
		}

		*staffMemberNum = allDoctors[selectionIndex]->getEmployeeNum();

		
		//staffMemberName = allDoctors[selectionIndex]->getName();
		return allDoctors[selectionIndex]->getName();
		//return staffMemberName;
	break;

	case 2:
		for (i = 0; i < allNurses.size(); i++)
			cout << i << ":  Nurse " << allNurses[i]->getName() << endl;

		cin >> selectionIndex;

		if (selectionIndex < 0 || selectionIndex > i - 1)
		{
			cout << "Ileggal selection entered!\nExiting...\n";
			return nullptr;
		}

		*staffMemberNum = allNurses[selectionIndex]->getEmployeeNum();
		return allNurses[selectionIndex]->getName();

		//return staffMemberName;
	break;
	default:
		cout << "Illegal sellection entered!\nExisiting...\n";
		*staffMemberNum = -1;
		return nullptr;
	}
}

bool Department::setNumOfPatients(int num)
{
	numOfPatients = num;
	return true;
}



vector<Doctor*> Department::getAllDoctors()
{
	return allDoctors;
}

vector<Nurse*> Department::getAllNurses()
{
	return allNurses;
}

vector<Patient*> Department::getAllPatients()
{
	return allPatients;
}

int Department::getNumOfDoctors() const
{
	return allDoctors.size();
}

int Department::getNumOfNurses() const
{
	return allNurses.size();
}

int Department::getNumOfPatients() const
{
	return numOfPatients;
}

void Department::printDepartment() const
{
	cout << "Department name: " << name << endl;
	cout << "--------------------------------------------------------" << endl;
	int i = 0;

	cout << "List of Doctors in the department (" << allDoctors.size() << "): " << endl;
	for (i = 0; i < allDoctors.size(); i++) {
		allDoctors[i]->print();
		cout << endl;
	}

	cout << "List of Nurses in the department (" << allNurses.size() << "): " << endl;
	for (i = 0; i < allNurses.size(); i++) {
		// change to ostream ----- allNurses[i]->print();
		cout << allNurses[i];
		cout << endl;
	}

	cout << "List of Patients in the department (" << allPatients.size() << "): " << endl;
	for (i = 0; i < allPatients.size(); i++) {
		allPatients[i]->printPatient();
		cout << endl;
	}

	cout << "--------------------------------------------------------" << endl;
}

void Department::printPatientsList() const
{
	cout << "Printing Patients list for department " << name << ":" << endl;

	for (int i = 0; i < allPatients.size(); i++)
	{
			allPatients[i]->printPatient();
			cout << endl;
			allPatients[i]->printCurrentVisit();
			cout << "\n\n";
	}
	cout << "--------------------------------------------------------" << endl;
}

void Department::printDepartmentStaff() const
{
	cout << "Staff members of Department " << name << ":" << endl;
	cout << "-----------------------------------------------------------" << endl;
	int i = 0;

	cout << "List of Doctors (" << allDoctors.size() << "): " << endl;
	//cout << "------------------------------------------" << endl;
	for (i = 0; i < allDoctors.size(); i++) {
		allDoctors[i]->print();
		cout << endl;
	}

	cout << endl;

	cout << "List of Nurses (" << allNurses.size() << "): " << endl;
	//cout << "------------------------------------------" << endl;
	for (i = 0; i < allNurses.size(); i++) {
		allNurses[i]->print();
		cout << endl;
	}

	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
}

bool Department::operator+=(Doctor* newDoctor)  
{
	addDoctor(newDoctor);
	return true;
}

bool Department::operator+=(Nurse* newNurse)  
{
	addNurse(newNurse);
	return true;
}
bool Department::operator+=(Patient* newPatient)
{
	addPatient(newPatient);
	return true;
}