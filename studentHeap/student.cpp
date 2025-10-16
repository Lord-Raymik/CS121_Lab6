#include <iostream>
#include <sstream>

//the header file
#include "student.h"
#include "address.h"
#include "date.h"

Student::Student() {
	Student::firstName = "";
	Student::lastName = "";
	Student::address = new Address();
	Student::birthday = new Date();
	Student::expectedGradDate = new Date();
	Student::creditHoursComplete = 0;
} //end constructor

Student::~Student() {
	//removing student variables from the heap
	delete Student::address;
	delete Student::birthday;
	delete Student::expectedGradDate;
} //end deconstructor

Date* Student::getBirthday() {
	return Student::birthday;
} // end getBirthday

Date* Student::getExpectedGradDate() {
	return Student::expectedGradDate;
} // end getExpectedGradDate

int Student::getCreditHours() {
	return Student::creditHoursComplete;
} // end getCreditHours

void Student::init(std::string studentString) {
	std::stringstream converter;
	std::string sStreet;
	std::string sCity;
	std::string sState;
	std::string sZip;
	std::string sBirthday;
	std::string sGradDate;
	std::string sCreditHours;

	converter.str(studentString);

	getline(converter, Student::firstName, ',');
	getline(converter, Student::lastName, ',');
	getline(converter, sStreet, ',');
	getline(converter, sCity, ',');
	getline(converter, sState, ',');
	getline(converter, sZip, ',');
	getline(converter, sBirthday, ',');
	getline(converter, sGradDate, ',');
	getline(converter, sCreditHours, ',');

	Student::address->init(sStreet, sCity, sState, sZip);
	Student::birthday->init(sBirthday);
	Student::expectedGradDate->init(sGradDate);

	converter.clear();
	converter.str("");

	converter << sCreditHours;
	converter >> Student::creditHoursComplete;
} //end init

void Student::printStudent() {
	std::cout << Student::firstName << " " << Student::lastName << std::endl;
	Student::address->printAddress();
	std::cout << "DOB: ";
	Student::birthday->printDate();
	std::cout << "Grad: ";
	Student::expectedGradDate->printDate();
	std::cout << "Credits: " << Student::creditHoursComplete << std::endl;
} //end printStudent

std::string Student::getLastFirst() {
	std::stringstream ss;
	ss.clear();
	ss.str("");
	ss << Student::lastName << ", " << Student::firstName;
	return ss.str();
} //end getLastFirst
