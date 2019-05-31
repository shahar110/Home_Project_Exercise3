#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

#include "nurse.h"
#include "department.h"
#include "doctor.h"
#include "SurgeonDoc.h"
#include "ResearchDoc.h"
#include "researcher.h"
#include "article.h"
#include "hospital.h"
#include "date.h"

#define PURPOSE_LENGTH 200

void addDepartment(Hospital& hospital);
void addNurse(Hospital& hospital);
void addDoctor(Hospital& hospital);
void addPatient(Hospital& hospital);
void addResearcher(Hospital& hospital);
void addArticles(Hospital& hospital);
void printDepartmentPatients(Hospital& hospital);
void printAllStaffMembers(Hospital& hospital);
void printAllResearchers(Hospital& hospital);
void findAndPrintPatient(Hospital& hospital);
void testOverloadedOperators(Hospital& hospital);
int selectPatient(Hospital& hospital);
int selectResearchers(Hospital& t);
int departmentSelect(Hospital& t);
void test(Hospital& hospital);
void researcherTest(Hospital& hospital);
void inheritenceTest(Hospital& hospital);

void main()
{
	Hospital hospital("Academic Hospital");
	int option = 0;
	cout << "Hello and welcome to Tel-Aviv Academic College Hospital!\n" << endl;
	while (option != -1)
	{
		cout << "Please select one of the following options:" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1: Add Department(s) to the Hospital" << endl;
		cout << "2: Add Nurse(s) to the Hospital and assign her to a Department" << endl;
		cout << "3: Add Doctor(s) to the Hospital and assign him to a Department" << endl;
		cout << "4: Add Patient and/or open Visitation Form to new/existing Patient" << endl;
		cout << "5: Add Researcher(s) to the Hospital" << endl;
		cout << "6: Add Article(s) to a Researcher" << endl;
		cout << "7: Print Patients list of a specific Deprtment" << endl;
		cout << "8: Print all staff members of the Hospital" << endl;
		cout << "9: Print all Researchers of the Hospital Research Institute" << endl;
		cout << "10: Find Patient and print its details" << endl;
		cout << "11: Test logical operators" << endl;
		cout << "-1: Quit" << endl;
		cin >> option;
		
		switch (option)
		{
		case -1:
			cout << "-------------------------------------------" << endl;
			cout << "-------------------------------------------" << endl;
			cout << "-------------------------------------------" << endl;
			cout << "Thank You For Using Academic Software"<<endl;
			break;
		case 1:
			addDepartment(hospital);
			break;
		case 2:
			addNurse(hospital);
			break;
		case 3:
			addDoctor(hospital);
			break;
		case 4:
			addPatient(hospital);
			break;
		case 5:
			addResearcher(hospital);
			break;
		case 6:
			addArticles(hospital);
			break;
		case 7:
			printDepartmentPatients(hospital);
			break;
		case 8:
			printAllStaffMembers(hospital);
			break;
		case 9:
			printAllResearchers(hospital);
			break;
		case 10:
			findAndPrintPatient(hospital);
			break;
		case 11:
			testOverloadedOperators(hospital);
			break;
		case 12:
			test(hospital);
			break;
		case 13:
			researcherTest(hospital);
			break;
		case 14:
			inheritenceTest(hospital);
			break;
		default:
			cout << "Ileggal selection entered!\nPlease enter a number (1 - 10)\n" << endl;
		}
	}
}

void addDepartment(Hospital& hospital)
{
	char depName[20];
	bool addMoreFlag = true;
	char charInput;

	while (addMoreFlag)
	{
		cout << "Enter the name of the Department you wish to add:\n";
		cin.getline(depName, 20);
		cin.getline(depName, 20);
		hospital.addDepartment(depName);

		cout << "Press any key to add more Department(s), to quit press 'q'\n";
		cin >> charInput;
		if (charInput == 'q' || charInput == 'Q')
			addMoreFlag = false;
	}
}

void addNurse(Hospital& hospital)
{
	char name[NAME_LENGTH];
	int experience;
	int selectDepartment;

	bool addMoreFlag = true;
	char charInput;

	if (hospital.getNumOfDepartments() == 0)
	{
		cout << "No departments in the Hospital!\nExiting...\n";
	}
	else
	{
		while (addMoreFlag)
		{
			cout << "Enter the Nurse's name: " << endl;
			cin.getline(name, NAME_LENGTH);
			cin.getline(name, NAME_LENGTH);

			cout << "Enter the Nurse's experience in years: " << endl;
			cin >> experience;

			selectDepartment = departmentSelect(hospital);
			if (selectDepartment == -1)
			{
				return;
			}
			hospital.addNurse(name, experience, selectDepartment);

			cout << "Press any key to add more Nurse(s), to quit press 'q'\n";
			cin >> charInput;
			if (charInput == 'q' || charInput == 'Q')
				addMoreFlag = false;
		}
	}
}

void addDoctor(Hospital& hospital)
{
	char name[NAME_LENGTH];
	char expertise[NAME_LENGTH];
	
	int selectDepartment, doctorType, numOfSurgeries;

	bool addMoreFlag = true;
	char charInput;

	if (hospital.getNumOfDepartments() == 0)
	{
		cout << "No departments in the Hospital!\nExiting...\n";
	}
	else
	{
		while (addMoreFlag)
		{
			cout << "Enter the Doctor's name: " << endl;
			cin.getline(name, NAME_LENGTH);
			cin.getline(name, NAME_LENGTH);

			cout << "Enter the Doctor's field of expertise: " << endl;
			cin.getline(expertise, NAME_LENGTH);

			selectDepartment = departmentSelect(hospital);
			if (selectDepartment == -1)
			{
				return;
			}

			cout << "Select the Doctor's profession:" << endl;
			cout << "0: Doctor" << endl;
			cout << "1: Surgeon Doctor" << endl;
			cout << "2: Research Doctor" << endl;

			cin >> doctorType;
			if (doctorType < 0 || doctorType > 2)
			{
				cout << "Ileggal selection entered!\nExiting...\n";
				return;
			}

			switch (doctorType)
			{
			case 0:
				hospital.addDoctor(name, expertise, selectDepartment);
				break;
			case 1:
				cout << "Enter the Surgeon's number of performed surgeries:" << endl;
				cin >> numOfSurgeries;
				hospital.addSurgeon(name, expertise, selectDepartment, numOfSurgeries);
				break;
			case 2:
				hospital.addResearchDoctor(name, expertise, selectDepartment);
				break;
			}
			
			cout << "Press any key to add more Doctor(s), to quit press 'q'\n";
			cin >> charInput;
			if (charInput == 'q' || charInput == 'Q')
				addMoreFlag = false;
		}
	}
}

int selectPatient(Hospital& hospital)
{
	int selection;
	int i;
	cout << "Select the Patient from the Hospital patients list:\n";
	for (i = 0; i < hospital.getNumOfPatients(); i++)
	{
		cout << i << ": " << hospital.getPatientsArr()[i]->getName() << "    , ID: " << hospital.getPatientsArr()[i]->getId() << endl;
	}

	cin >> selection;
	if (selection < 0 || selection > i - 1)
	{
		cout << "Ileggal number entered!\nExiting...\n";
		return -1;
	}
	else
	{ 
		return selection;
	}
}

void addVisit(Hospital& hospital, int patientId, int departmentIndex)
{
	string departmentName;
	int patientIndex, staffMemberId;
	string therapistName;
	int day;
	int month;
	int year;
	int purpose;
	cout << "Select the purpose of the Patient's visit:\n0: for Surgery\n1: for Examination" << endl;
	cin >> purpose;
	if (purpose < 0 || purpose > 1)
	{
		cout << "Illegal selection entered!\nExiting..."<<endl;
		return;
	}
	//get the ID num and name of the department staff member (therapist) selected by the user
	therapistName = hospital.getDeparmentsArr()[departmentIndex]->selectStaffMember(&staffMemberId);

	//get the name of the department
	departmentName = hospital.getDeparmentsArr()[departmentIndex]->getName();

	//get the current date (T.B.D)
	cout << "Enter arrival date: " << endl;
	cout << "Day of month (1 - 31): ";
	cin >> day;

	cout << "Enter month (1 - 12): ";
	cin >> month;

	cout << "Enter year (4 digits): ";
	cin >> year;

	try
	{
		Date d1(day, month, year);

		//get the index of the patient in the hospital patientArr
		patientIndex = hospital.findPatientIndex(patientId);

		//add the visit details to the patient
		hospital.getPatientsArr()[patientIndex]->addVisit(d1, purpose, staffMemberId, therapistName, departmentName);
	}
	catch (DateDayException& e)
	{
		e.show();
	}
	catch (DateMonthException& e)
	{
		e.show();
	}
	catch (DateYearException& e)
	{
		e.show();
	}
	catch (VisitationRoomException& e)
	{
		e.show();
	}
}

void addPatient(Hospital& hospital)
{
	char name[NAME_LENGTH];
	int id, birthYear, genderNum;
	int selectDepartment, selectPtn;
	eGender gender;

	bool addMoreFlag = true;
	char charInput;

	cout << "Have the patient visited the Hospital before? ('Y' - Yes , 'N' - No)\n";
	cin >> charInput;

	if (charInput == 'Y' || charInput == 'y')
	{
		if (hospital.getNumOfPatients() == 0)
		{
			cout << "No Patients in the Hospital!\nExiting...\n";
		}
		else
		{
			selectPtn = selectPatient(hospital);
			if (selectPtn == -1)
			{
				return;
			}
			selectDepartment = departmentSelect(hospital);
			if (selectDepartment == -1)
			{
				return;
			}
			id = hospital.getPatientsArr()[selectPtn]->getId();
			if (selectDepartment != hospital.getPatientsArr()[selectPtn]->getDepartmentIndex())
			{
				hospital.changePatientDepartment(id, selectDepartment);
			}
			addVisit(hospital, id, selectDepartment);
		}
	}
	else {
		if (charInput == 'N' || charInput == 'n')
		{
			if (hospital.getNumOfDepartments() == 0)
			{
				cout << "No departments in the Hospital!\nExiting...\n";
				return;
			}
			cout << "Adding new Patient\n";
			cout << "Enter the Patient's name:" << endl;
			cin.getline(name, NAME_LENGTH);
			cin.getline(name, NAME_LENGTH);

			cout << "Enter the Patient's ID number:" << endl;
			cin >> id;

			cout << "Enter the Patient's year of birth:" << endl;
			cin >> birthYear;

			cout << "Enter the Patient's Gender:  (0 - Male : 1 - Female)" << endl;
			cin >> genderNum;
			gender = (eGender)genderNum;

			selectDepartment = departmentSelect(hospital);
			if (selectDepartment == -1)
			{
				return;
			}

			try 
			{
				hospital.addPatient(name, id, birthYear, gender, selectDepartment);
				addVisit(hospital, id, selectDepartment);
			}
			catch (PatientNameException& e)
			{
				e.show();
			}
			catch (PatientIdException& e)
			{
				e.show();
			}
			catch (PatientYearException& e)
			{
				e.show();
			}

		}
		else
		{
			cout << "Illegal input entered!\nExiting...\n";
		}
	}
}

void findAndPrintPatient(Hospital& hospital)
{
	int id, patientIndex;

	bool addMoreFlag = true;
	char charInput;

	while (addMoreFlag)
	{
		cout << "Enter the ID number of the Patient you wish to find:" << endl;
		cin >> id;
		patientIndex = hospital.findPatientIndex(id);

		if (patientIndex != -1)
		{
			hospital.getPatientsArr()[patientIndex]->printPatient();
			cout << endl;
			hospital.getPatientsArr()[patientIndex]->printCurrentVisit();
			cout << "\n\n";
		}
		else
		{
			cout << "Patient ID not found!" << endl;
		}

		cout << "Press any key to search another Patient, to quit press 'q'\n";
		cin >> charInput;
		if (charInput == 'q' || charInput == 'Q')
			addMoreFlag = false;
	}
}


void addResearcher(Hospital& hospital)
{
	char name[NAME_LENGTH];

	bool addMoreFlag = true;
	char charInput;

	while (addMoreFlag)
	{
		cout << "Enter the Researcher's name: " << endl;
		cin.getline(name, NAME_LENGTH);
		cin.getline(name, NAME_LENGTH);

		hospital.addResearcher(name);

		cout << "Press any key to add more Researcher(s), to quit press 'q'\n";
		cin >> charInput;
		if (charInput == 'q' || charInput == 'Q')
			addMoreFlag = false;
	}
}

void addArticles(Hospital& hospital)
{
	char articleName[NAME_LENGTH];
	char magazineName[NAME_LENGTH];
	int day;
	int month;
	int year;
	int selectResearcher;

	bool addMoreArticlesFlag = true;
	bool addToResearcherFlag = true;
	char charInput;

	if (hospital.getNumOfResearchers() == 0)
	{
		cout << "No Researchers in the Hospital!\nExiting...\n";
		return;
	}

	cout << "Select the number of the Researcher you wish to add Articles to\n";
	selectResearcher = selectResearchers(hospital);
	if (selectResearcher == -1)
	{
		return;
	}
	while (addToResearcherFlag)
	{
		cout << "Enter the Article name: " << endl;
		cin.getline(articleName, NAME_LENGTH);
		cin.getline(articleName, NAME_LENGTH);

		cout << "Enter its Magazine name: " << endl;
		cin.getline(magazineName, NAME_LENGTH);

		cout << "Enter its publish date: " << endl;
		cout << "Day of month (1 - 31): ";
		cin >> day;

		cout << "Enter month (1 - 12): ";
		cin >> month;

		cout << "Enter year (4 digits): ";
		cin >> year;

		try 
		{
			Date d1(day, month, year);
			hospital.getResearchersArr()[selectResearcher]->addArticle(articleName, magazineName, d1);

		}
		catch (DateDayException& e)
		{
			e.show();
		}
		catch (DateMonthException& e)
		{
			e.show();
		}
		catch (DateYearException& e)
		{
			e.show();
		}


		cout << "Press any key to add more Article(s) to the selected Researcher, to quit press 'q'\n";
		cin >> charInput;
		if (charInput == 'q' || charInput == 'Q')
			addToResearcherFlag = false;
	}
}

void printDepartmentPatients(Hospital& hospital)
{
	int departmentIndex = departmentSelect(hospital);

	if (departmentIndex == -1)
	{
		return;
	}

	hospital.getDeparmentsArr()[departmentIndex]->printPatientsList();
}

void printAllStaffMembers(Hospital& hospital)
{
	for (int i = 0; i < hospital.getNumOfDepartments(); i++) {
		hospital.getDeparmentsArr()[i]->printDepartmentStaff();
	}
}

void printAllResearchers(Hospital& hospital)
{
	for (int i = 0; i < hospital.getNumOfResearchers(); i++)
	{
		// change to ostream ----- hospital.getResearchersArr()[i]->printDetails();
		cout << *(hospital.getResearchersArr()[i]);
		cout << "\n------------------------------------------------" << endl;
		hospital.getResearchersArr()[i]->printArticleList();
		cout << "\n------------------------------------------------" << endl;
	}
}

int selectResearchers(Hospital& t)
{
	int select = 0;
	int i;

	for (i = 0; i < t.getNumOfResearchers(); i++)
	{
		cout << i << ". " << t.getResearchersArr()[i]->getName() << endl;
	}
	cin >> select;
	if (select < 0 || select > i - 1)
	{
		cout << "Ileggal selection entered!\nExiting...\n";
		return - 1;
	}
	return select;
}

int departmentSelect(Hospital& t)
{
	int select = 0;
	int i;
	cout << "Select the number of the department\n";
	for (i = 0; i < t.getNumOfDepartments(); i++)
	{
		cout  << i << ". " << t.getDeparmentsArr()[i]->getName() << endl;
	}
	cin >> select;

	if (select < 0 || select > i - 1)
	{
		cout << "Ileggal selection entered!\nExiting...\n";
		return -1;
	}

	return select;
}

void testOverloadedOperators(Hospital & hospital)
{
	int L_Value, R_Value, slecectedOperator;
	int testMoreFlag = 1;
	char charInput;

	if (hospital.getNumOfResearchers() < 2) {
		cout << "Please first add at least two Researchers to the hospital in order to test logical operations.\nExiting..." << endl;
		return;
	}
	cout << "Select the L value:\n";
	L_Value = selectResearchers(hospital);
	cout << "Resercher " << hospital.getResearchersArr()[L_Value]->getName() << " was selected, number of articles: " << hospital.getResearchersArr()[L_Value]->getNumOfArticles() << endl;
	cout << "Select the R value:\n";
	R_Value = selectResearchers(hospital);
	cout << "Resercher " << hospital.getResearchersArr()[R_Value]->getName() << " was selected, number of articles: " << hospital.getResearchersArr()[R_Value]->getNumOfArticles() << endl;

	while (testMoreFlag)
	{
		cout << "Slect the tested logic operator:" << endl;
		cout << "1: L_Value < R_Value" << endl;
		cout << "2: L_Value > R_Value" << endl;
		cout << "3: L_Value == R_Value" << endl;
		cout << "4: L_Value != R_Value" << endl;
		cout << "5: L_Value <= R_Value" << endl;
		cout << "6: L_Value >= R_Value" << endl;
		cin >> slecectedOperator;

		if (slecectedOperator < 1 || slecectedOperator > 6)
		{
			cout << "Illegal selection entered!\nExiting..." << endl;
			return;
		}
		switch (slecectedOperator)
		{
		case 1:
			cout << hospital.getResearchersArr()[L_Value]->getName() << "  <  " << hospital.getResearchersArr()[R_Value]->getName() << endl;
			if (*(hospital.getResearchersArr()[L_Value]) < *(hospital.getResearchersArr()[R_Value]))
				cout << "True!\n";
			else
				cout << "False!\n";
			break;
		case 2:
			cout << hospital.getResearchersArr()[L_Value]->getName() << "  >  " << hospital.getResearchersArr()[R_Value]->getName() << endl;
			if (*(hospital.getResearchersArr()[L_Value]) > *(hospital.getResearchersArr()[R_Value]))
				cout << "True!\n";
			else
				cout << "False!\n";
			break;
		case 3:
			cout << hospital.getResearchersArr()[L_Value]->getName() << "  ==  " << hospital.getResearchersArr()[R_Value]->getName() << endl;
			if (*(hospital.getResearchersArr()[L_Value]) == *(hospital.getResearchersArr()[R_Value]))
				cout << "True!\n";
			else
				cout << "False!\n";
			break;
		case 4:
			cout << hospital.getResearchersArr()[L_Value]->getName() << "  !=  " << hospital.getResearchersArr()[R_Value]->getName() << endl;
			if (*(hospital.getResearchersArr()[L_Value]) != *(hospital.getResearchersArr()[R_Value]))
				cout << "True!\n";
			else
				cout << "False!\n";
			break;
		case 5:
			cout << hospital.getResearchersArr()[L_Value]->getName() << "  <=  " << hospital.getResearchersArr()[R_Value]->getName() << endl;
			if (*(hospital.getResearchersArr()[L_Value]) <= *(hospital.getResearchersArr()[R_Value]))
				cout << "True!\n";
			else
				cout << "False!\n";
			break;
		case 6:
			cout << hospital.getResearchersArr()[L_Value]->getName() << "  >=  " << hospital.getResearchersArr()[R_Value]->getName() << endl;
			if (*(hospital.getResearchersArr()[L_Value]) >= *(hospital.getResearchersArr()[R_Value]))
				cout << "True!\n";
			else
				cout << "False!\n";
			break;
		}

		cout << "Press any key to test more logic operators, to quit press 'q'\n";
		cin >> charInput;
		if (charInput == 'q' || charInput == 'Q')
			testMoreFlag = false;
	}
}

void test(Hospital& hospital)
{
	//int patientIndex, currentVisit;
	hospital.addDepartment("Pnimit A");
	hospital.addDepartment("Pnimit B");
	hospital.addDepartment("Pnimit C");
	hospital.addDepartment("Pnimit D");
	hospital.addDepartment("Pnimit E");

	hospital.addNurse("Sharon", 1, 0);
	hospital.addNurse("Adi", 3, 0);
	hospital.addNurse("Adva", 5, 0);
	hospital.addNurse("Michal", 2, 1);
	hospital.addNurse("Nastia", 4, 2);
	hospital.addNurse("Varda", 6, 3);
	hospital.addNurse("Billah", 6, 4);

	hospital.addSurgeon("David", "Palms", 1, 50);
	hospital.addSurgeon("Richard", "Knees", 1, 60);

	hospital.addResearchDoctor("Biatrix", "Melven", 4);
	hospital.addResearchDoctor("Boris", "Mendelblit", 4);

	hospital.addDoctor("Simon", "Heart", 0);
	hospital.addDoctor("Gurfunkel", "Legs", 0);
	hospital.addDoctor("Ovadia", "Brain", 0);
	hospital.addDoctor("Zacariah", "Hands", 1);
	hospital.addDoctor("Moshe", "Skin", 2);
	hospital.addDoctor("Shlomi", "Heart", 3);
	hospital.addDoctor("Pini", "Head", 4);

	hospital.addSurgeon("Gabriel", "Cardio", 0, 30);
	hospital.addSurgeon("Samual", "Leaver", 0, 40);

	hospital.addResearchDoctor("Thomas", "Addison", 0);
	hospital.addResearchDoctor("Tulvard", "Hanso", 3);

	Date d1(29, 7, 1991), d2(12, 03, 1957);

	((ResearchDoctor*)hospital.getDoctorsArr()[2])->addArticle("News", "Time Magazine", d1);
	//hospital.getResearchersArr()[0]->addArticle("Sports", "New York Times", d1);
	//hospital.getResearchersArr()[0]->addArticle("Science", "Washingtone Post", d2);
	//hospital.getResearchersArr()[1]->addArticle("Entertinment", "The Economist", d1);
	//hospital.getResearchersArr()[2]->addArticle("Technological", "PC Magazine", d2);

	hospital.addPatient("Amos", 1111, 1980, Male, 0);
	hospital.addPatient("Gilad", 2222, 1981, Male, 0);
	hospital.addPatient("Sarit", 3333, 1982, Female, 1);
	hospital.addPatient("Tehila", 4444, 1983, Female, 1);

	//hospital.getPatientsArr()[0]->addVisit(d1, "Purpose 1", 1, "Simon", "Pnimit A");
	//hospital.getPatientsArr()[1]->addVisit(d1, "Purpose 2", 2, "Gurfunkel", "Pnimit A");
	//hospital.getPatientsArr()[2]->addVisit(d1, "Purpose 3", 3, "Sharon", "Pnimit B");
	//hospital.getPatientsArr()[3]->addVisit(d1, "Purpose 4", 4, "Adi", "Pnimit B");

	//for (int i = 0; i < 3; i++)
	//{
	//	hospital.getPatientsArr()[i]->printPatient();
	//	cout << endl;
	//	currentVisit = hospital.getPatientsArr()[i]->getVisitCounter() - 1;
	//	hospital.getPatientsArr()[i]->getVisitsArr()[currentVisit]->printVisitForm();
	//	cout << endl;
	//}
}

void researcherTest(Hospital& hospital)
{
	hospital.addResearcher("Isic");
	hospital.addResearcher("Newton");
	hospital.addResearcher("Einstien");
	hospital.addResearcher("Indiana Johnes");
	hospital.addResearcher("John Lock");

	Date d1(29, 7, 1991), d2(12, 03, 1957);
	hospital.getResearchersArr()[0]->addArticle("News", "Time Magazine", d1);
	hospital.getResearchersArr()[0]->addArticle("Sports", "New York Times", d1);
	hospital.getResearchersArr()[0]->addArticle("Science", "Washingtone Post", d2);
	hospital.getResearchersArr()[1]->addArticle("Entertinment", "The Economist", d1);
	hospital.getResearchersArr()[2]->addArticle("Technological", "PC Magazine", d2);
}

void inheritenceTest(Hospital& hospital) 
{
	ResearchDoctor rd1("Avi", "Kelvin");
	ResearchDoctor rd2("Sibony", "Martian");

	Date d1(29, 7, 1991), d2(12, 03, 1957);

	rd1.addArticle("News", "Time Magazine", d1);
	rd1.addArticle("Sports", "New York Times", d1);
	rd1.addArticle("Science", "Washingtone Post", d2);
	rd2.addArticle("Entertinment", "The Economist", d1);
	rd2.addArticle("Technological", "PC Magazine", d2);

	rd1.print();
	cout << endl;
	rd1.printArticleList();
	cout << endl;
	rd2.print();
	cout << endl;
	rd2.printArticleList();
	cout << endl;
}
//commit test