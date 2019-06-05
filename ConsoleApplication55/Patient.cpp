#include "Patient.h"

Patient::Patient(const string& name, int id, int birthYear, eGender gender)
{
	setName(name);
	setId(id);
	setBirthYear(birthYear);
	setGender(gender);
}

bool Patient::setName(const string& newName) throw (PatientNameException)
{
	if (newName.length() > 20 || newName.empty())
		throw PatientNameException(newName);

	name = newName;
	return true;
}

bool Patient::setId(long newId) throw (PatientIdException)
{
	if (newId < 1 || newId > 999999999999)
		throw PatientIdException(newId);

	id = newId;
	return true;
}

bool Patient::setBirthYear(int newBirthYear) throw (PatientYearException)
{
	if (newBirthYear < 1000 || newBirthYear > 9999)
		throw PatientYearException(newBirthYear);

	birthYear = newBirthYear;
	return true;
}

bool Patient::setGender(eGender newGender)
{
	gender = newGender;
	return true;
}

bool Patient::addVisit(const Date& arrivalDate, int purpose, int therapistNum, const string& therapistName, const string& departmentName)
{
	//Add the new Visit Form to the Patient visits array
	if (purpose == CHECK) {
		visitsArr.push_back(new VisitForm(arrivalDate, purpose, therapistNum, therapistName, departmentName));
	}
	else {
		int isFasting, roomNum;
		cout << "Is the patient fasting? \n0: Fasting \n1: Not fasting " << endl;
		cin >> isFasting;
		cout << "Enter room number : " << endl;
		cin >> roomNum;
		visitsArr.push_back(new surgeryVisitation(arrivalDate, purpose, therapistNum, therapistName, departmentName,roomNum, isFasting));
	}
	visitHistoryCounter++;
	return true;
}

bool Patient::setDepartmentIndex(int index)
{
	departmentIndex = index;
	return true;
}

bool Patient::setDepartmentPatientArrIndex(int index)
{
	departmentPatientArrIndex = index;
	return true;
}


int Patient::getId() const
{
	return id;
}

int Patient::getBirthYear() const
{
	return birthYear;
}

eGender Patient::getGender() const
{
	return gender;
}

vector<VisitForm*> Patient::getVisitsArr() const
{
	return visitsArr;
}

int Patient::getDepartmentIndex() const
{
	return departmentIndex;
}

int Patient::getDepartmentPatientArrIndex() const
{
	return departmentPatientArrIndex;
}

//Department* Patient::getDepartment(int *departmentIndex) const
//{
//	*departmentIndex = departmentPatientIndex;
//	return department;
//}

int Patient::getVisitCounter() const
{
	return visitHistoryCounter;
}

void Patient::printPatient()
{
	cout << "Patient name: " << name << "   , ID: " << id << "   , Birth Year: " << birthYear << "   , Gender: " << genders[gender];
}

void Patient::printCurrentVisit()
{
	if (visitHistoryCounter > 0)
	{
		visitsArr[visitHistoryCounter - 1]->printVisitForm();
	}
	else
	{
		cout << "No visits recorded for the patient!\n";
	}
}