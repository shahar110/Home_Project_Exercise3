#include "date.h"

Date::Date(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

bool Date::setDay(int newDay) throw (DateDayException)
{
	if (newDay < 1 || newDay > 31)
		throw DateDayException(newDay);

	day = newDay;
	return true;
}

bool Date::setMonth(int newMonth) throw (DateMonthException)
{
	if (newMonth < 1 || newMonth > 12)
		throw DateMonthException(newMonth);

	month = newMonth;
	return true;
}

bool Date::setYear(int newYear) throw (DateYearException)
{
	if (newYear < 1000 || newYear > 9999)
		throw DateYearException(newYear);

	year = newYear;
	return true;
}

void Date::printDate() const
{
	cout << day << "/" << month << "/" << year;
}

Date::Date(ifstream &in)
{
	in.read((char*)this, sizeof(*this));

}

void Date::save(ofstream &out)
{
	out.write((const char*)this, sizeof(*this));
}
