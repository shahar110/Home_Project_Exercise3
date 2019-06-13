#include "hospital.h"

int Hospital::employeeCounter = 0;

Hospital::Hospital(const string& name) 
{
	setName(name);
	loadingFromFile();

}

void Hospital::loadingFromFile()
{
	/* changing to files*/
	int numOfDocs = 0;
	ifstream inFile("Hospital.txt");
	inFile >> numOfDepartments;
	for (int i = 0; i < numOfDepartments; i++)
	{
		Department* newDepartment = new Department(inFile);
		departmentArr.push_back(newDepartment);
		inFile >> numOfDocs;
		departmentArr[i]->setNumOfDoctors(numOfDocs);
	}
	inFile >> numOfDoctors;
	cout << numOfDoctors << endl;
	for (int i = 0; i < numOfDoctors; i++)
	{
		Doctor *d = nullptr;
		char type[20];
		int tmpIndex;
		inFile >> type;
		inFile >> tmpIndex;
		if (strcmp(type, typeid(Doctor).name() + 6) == 0)
			 d = new Doctor(inFile);
		else if (strcmp(type, typeid(SurgeonDoctor).name() + 6) == 0)
			 d = new SurgeonDoctor(inFile);
		else if (strcmp(type, typeid(ResearchDoctor).name() + 6) == 0)
			 d = new ResearchDoctor(inFile);

		departmentArr[tmpIndex]->getAllDoctors().push_back(d);
		doctorsArr.push_back(d);
	}
	//for (int i = 0; i < numOfDoctors; i++)
	//{
	//	Doctor* d = new Doctor(inFile);
	//	*(departmentArr[d->getIndex()]) += d;
	//	doctorsArr.push_back(d);
	//}
	inFile.close();
}
/*
How we save ? 
Num of all departments 
name of specific department
amount of doctors 
names of them
amount of nurses 
names of them
*/
void Hospital::saveToFile()
{
	ofstream outFile("Hospital.txt", ios::trunc);
	outFile << numOfDepartments << endl;
	for (int i = 0; i < numOfDepartments; i++)
	{
		outFile << departmentArr[i]->getName() << endl;
		outFile << departmentArr[i]->getNumOfDoctors() << endl;
	}
	// saving doctors also
	outFile << doctorsArr.size() << endl;
	for (int j = 0; j < doctorsArr.size() ; j++)
	{
		outFile << typeid(*doctorsArr[j]).name() + 6 << " " << doctorsArr[j]->getIndex() << " " << doctorsArr[j]->getName() << " " << doctorsArr[j]->getExpertise();
		if (strcmp(typeid(*doctorsArr[j]).name(), typeid(SurgeonDoctor).name()) == 0)
			outFile << " " << ((SurgeonDoctor*)doctorsArr[j])->getNumOfSurgeries();
		outFile << endl;
	}
}
Hospital::~Hospital()
{
	saveToFile();
	
}

void Hospital::addDepartment(const string& departmentName)
{
	
	Department* newDepartment = new Department(departmentName);
	departmentArr.push_back(newDepartment);
	numOfDepartments++;
}

int Hospital::getNumOfDepartments() const
{
	return numOfDepartments;
}

vector<Department*> Hospital::getDeparmentsArr()
{
	return departmentArr;
}

void Hospital::addNurse(const string& nurseName, int years, int depratmentIndex)
{	
	try
	{
		//Add the new Nurse to the Hospital Nurses array
		Nurse* n = new Nurse(nurseName, years);
		n->setIndex(depratmentIndex);
		nursesArr.push_back(n);

		//Add the pointer to the Nurse to the her department Nurses pointers arr
		*(departmentArr[depratmentIndex]) += *(nursesArr.end() - 1);

		//departmentArr[depratmentIndex]->addNurse(*(nursesArr.end() - 1));
	}
	catch (NurseExperException& e)
	{
		e.show();
	}
	catch (StaffMemberNameException& e)
	{
		e.show();
	}
}

int Hospital::getNumOfNurses() const
{
	return nursesArr.size();
}

vector<Nurse*> Hospital::getNursesArr()
{
	return nursesArr;
}

void Hospital::addDoctor(const string& doctorName, const string& expertise, int depratmentIndex)
{
	try
	{
		//Add the new Doctor to the Hospital Doctors array
		Doctor* d = new Doctor(doctorName, expertise);
		d->setIndex(depratmentIndex);
		doctorsArr.push_back(d);

		//Add the pointer to the Doctor the his department Doctors pointers arr
		//departmentArr[depratmentIndex]->addDoctor(*(doctorsArr.end() - 1));

		// Trying to change by overloading operator
		*(departmentArr[depratmentIndex]) += *(doctorsArr.end() - 1);
	}
	catch (DoctorExperException& e)
	{
		e.show();
	}
	catch (StaffMemberNameException& e)
	{
		e.show();
	}
}

void Hospital::addSurgeon(const string& doctorName, const string& expertise, int depratmentIndex, int numOfSurgeries)
{
	try
	{
		//Add the new Doctor to the Hospital Doctors array
		Doctor* s = new SurgeonDoctor(doctorName, expertise, numOfSurgeries);
		s->setIndex(depratmentIndex);
		doctorsArr.push_back(s);

		//Add the pointer to the Doctor the his department Doctors pointers arr
		departmentArr[depratmentIndex]->addDoctor(*(doctorsArr.end() - 1));
	}
	catch (DoctorSurgeriesException& e)
	{
		e.show();
	}
	catch (DoctorExperException& e)
	{
		e.show();
	}
	catch (StaffMemberNameException& e)
	{
		e.show();
	}
}

int Hospital::getNumOfDoctors() const
{
	return doctorsArr.size();
}

vector<Doctor*> Hospital::getDoctorsArr()
{
	return doctorsArr;
}

void Hospital::addPatient(const string& patientName, int patientId, int birthYear, eGender patientGender, int depratmentIndex)
{
	Patient* newPatient = new Patient(patientName, patientId, birthYear, patientGender);
	patientArr.push_back(newPatient);
	*(departmentArr[depratmentIndex]) += *(patientArr.end() - 1);
	numOfPatients++;
}

void Hospital::changePatientDepartment(int patientId, int newDepartmentIndex)
{
	int patientIndex, oldDepartmentIndex, oldPatientArrIndex;

	patientIndex = findPatientIndex(patientId);
	oldDepartmentIndex = patientArr[patientIndex]->getDepartmentIndex();
	oldPatientArrIndex = patientArr[patientIndex]->getDepartmentPatientArrIndex();
	departmentArr[oldDepartmentIndex]->getAllPatients()[oldPatientArrIndex] = nullptr;

	int sizeToEnd = departmentArr[oldDepartmentIndex]->getNumOfPatients();
	int i;
	for (i = oldPatientArrIndex; i < sizeToEnd; i++)
	{
		departmentArr[oldDepartmentIndex]->getAllPatients()[i] = departmentArr[oldDepartmentIndex]->getAllPatients()[i + 1];
		int numOfPatients = departmentArr[oldDepartmentIndex]->getNumOfPatients();
		departmentArr[oldDepartmentIndex]->setNumOfPatients(numOfPatients - 1);
	}
	departmentArr[oldDepartmentIndex]->getAllPatients()[i] = nullptr;
	departmentArr[newDepartmentIndex]->addPatient(patientArr[patientIndex]);

	patientArr[patientIndex]->setDepartmentIndex(newDepartmentIndex);
}

int Hospital::getNumOfPatients() const
{
	return numOfPatients;
}

vector<Patient*> Hospital::getPatientsArr()
{
	return patientArr;
}

int Hospital::findPatientIndex(int id)
{
	for (int i = 0; i < numOfPatients; i++)
	{
		if (patientArr[i]->getId() == id)
			return i;
	}

	return -1;
}

void Hospital::addResearcher(const string& researcherName)
{
	try 
	{
		//Add the new Researcher to the Hospital Researchers array
		Researcher* r = new Researcher(researcherName);
		researchersArr.push_back(r);
	}
	catch (StaffMemberNameException& e)
	{
		e.show();
	}
}

int Hospital::getNumOfResearchers() const
{
	return researchersArr.size();
}

vector<Researcher*> Hospital::getResearchersArr()
{
	return researchersArr;
}

void Hospital::addResearchDoctor(const string& doctorName, const string& expertise, int depratmentIndex)
{
	try
	{

		ResearchDoctor* rs = new ResearchDoctor(doctorName, expertise);
		rs->setIndex(depratmentIndex);
		doctorsArr.push_back(rs);
		researchersArr.push_back(rs);

		//Add the pointer to the Doctor the his department Doctors pointers arr
		departmentArr[depratmentIndex]->addDoctor(*(doctorsArr.end() - 1));
		
	}
	catch (DoctorExperException& e)
	{
		e.show();
	}
	catch (StaffMemberNameException& e)
	{
		e.show();
	}
}

bool Hospital::setName(const string& newName)
{
	name = newName;
	return true;
}

