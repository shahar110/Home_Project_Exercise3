#include "surgeryVisitation.h"


surgeryVisitation::surgeryVisitation(const Date& date, int purpose, int therapistNum, const string& therapistName,
	const string& departmentName, int roomNum, int isFasting) : VisitForm(date, purpose, therapistNum, therapistName, departmentName)
{
	setIsFasting(isFasting);
	setRoomNum(roomNum);
}

bool surgeryVisitation::setIsFasting(int option)
{
	isFasting = (bool)option;
	return true;
}
bool surgeryVisitation::setRoomNum(int room) throw (VisitationRoomException)
{
	if (room < 1 || room > 9999)
		throw VisitationRoomException(room);

	roomNum = room;
	return true;
}

bool surgeryVisitation::getIsFasting()
{
	return isFasting;
}

int surgeryVisitation::getRoomNum()
{
	return roomNum;
}

void surgeryVisitation::printVisitForm()
{
	VisitForm::printVisitForm();
	cout << ",   room number: " << roomNum;
	if (isFasting)
		cout << ",   The patient didn't fast before sergery" << endl;
	else
		cout << ",   The patient fast before sergery" << endl;
}
