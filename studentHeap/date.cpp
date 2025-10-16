#include <iostream>
#include <sstream>

//the header file
#include "date.h"

Date::Date() {
	Date::month = 0;
	Date::day = 0;
	Date::year = 0;
}

bool Date::compare(Date* targetDate) {
	if (this->year < targetDate->getYear()) {
		return true;
	} else if (this->year == targetDate->getYear()) {
		if (this->month < targetDate->getMonth()) {
			return true;
		} else if (this->month == targetDate->getMonth()) {
			if (this->day < targetDate->getDay()) {
				return true;
			} else {
				return false;
			} // end if
		} else {
			return false;
		} // end if
	} else {
		return false;
	} // end if
}

int Date::getYear() {
	return Date::year;
}

int Date::getMonth() {
	return Date::month;
}

int Date::getDay() {
	return Date::day;
}

void Date::init(std::string date) {
	std::stringstream converter;
	std::stringstream ss;
	std::string sMonth;
	std::string sDay;
	std::string sYear;

	converter.str(date);

	getline(converter, sMonth, '/');
	getline(converter, sDay, '/');
	getline(converter, sYear, '/');

	converter.clear();
	converter.str("");

	converter << sMonth << " " << sDay << " " << sYear;
	converter >> Date::month >> Date::day >> Date::year;
}

void Date::printDate() {
	const std::string monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	std::cout << monthNames[Date::month - 1] << " " << Date::day << ", " << Date::year << std::endl;
}
