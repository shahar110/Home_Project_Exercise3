#pragma once
#include "VisitationForm.h"
#include "date.h"

class surgeryVisitation : public VisitForm
{
	int roomNum;
	bool isFasting;
public:
	surgeryVisitation(const Date& date, int purpose, int therapistNum, const string& therapistName, const string& departmentName, int roomNum, int isFasting);
	~surgeryVisitation();
	bool setRoomNum(int roomNum);
	bool setIsFasting(int answer);

	int getRoomNum();
	bool getIsFasting();
	void printVisitForm();
};

