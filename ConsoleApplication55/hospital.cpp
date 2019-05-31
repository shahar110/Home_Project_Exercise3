#include "hospital.h"

int Hospital::employeeCounter = 0;

Hospital::Hospital(const string& name) 
{
	setName(name);

	departmentArr = new Department*[physDepartmentsArr];
	patientArr = new Patient*[physPatientArr];
}

Hospital::~Hospital()
{
	delete[]departmentArr;
	delete[]patientArr;
}

void Hospital::addDepartment(const string& departmentName)
{
	if (physDepartmentsArr == numOfDepartments) {
		physDepartmentsArr *= 2;

		Department** temp = new Department*[numOfDepartments];
		for (int i = 0; i < numOfDepartments; i++)
			temp[i] = departmentArr[i];

		delete[]departmentArr;

		departmentArr = new Department*[physDepartmentsArr];
		for (int i = 0; i < numOfDepartments; i++)
			departmentArr[i] = temp[i];

		delete[]temp;
	}

	//Add the new Department to the Hospital Departments array
	departmentArr[numOfDepartments] = new Department(departmentName);
	numOfDepartments++;
}

int Hospital::getNumOfDepartments() const
{
	return numOfDepartments;
}

Department** Hospital::getDeparmentsArr()
{
	return departmentArr;
}

void Hospital::addNurse(const string& nurseName, int years, int depratmentIndex)
{	
	try
	{
		//Add the new Nurse to the Hospital Nurses array
		Nurse* n = new Nurse(nurseName, years);
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
		if (physPatientArr == numOfPatients) {
			physPatientArr *= 2;

			Patient** temp = new Patient*[numOfPatients];
			for (int i = 0; i < numOfPatients; i++)
				temp[i] = patientArr[i];

			delete[]patientArr;

			patientArr = new Patient*[physPatientArr];
			for (int i = 0; i < numOfPatients; i++)
				patientArr[i] = temp[i];

			delete[]temp;
		}

		//Add the new Patient to the Hospital Patients array
		patientArr[numOfPatients] = new Patient(patientName, patientId, birthYear, patientGender);

		//Add the pointer to the Patient the his department Patients pointers arr
		departmentArr[depratmentIndex]->addPatient(patientArr[numOfPatients]);
		//Save the department index for the Patient (for later use)
		patientArr[numOfPatients]->setDepartmentIndex(numOfPatients);

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
	for (i = oldPatientArrIndex ; i < sizeToEnd ; i++)
	{
		departmentArr[oldDepartmentIndex]->getAllPatients()[i] = departmentArr[oldDepartmentIndex]->getAllPatients()[i+1];
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

Patient** Hospital::getPatientsArr()
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
		//Add the new Doctor to the Hospital Doctors array
		//doctorsArr[numOfDoctors] = new ResearchDoctor(doctorName, expertise);
		//researchersArr[numOfResearchers] = (ResearchDoctor*) doctorsArr[numOfDoctors];

		ResearchDoctor* rs = new ResearchDoctor(doctorName, expertise);
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