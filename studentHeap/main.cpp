#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "date.h"
#include "address.h"
#include "student.h"

std::vector<Student*> loadStudents();
void printStudents(std::vector<Student*> students);
void printStudentNames(std::vector<Student*> students);
void findStudent(std::vector<Student*> students);
void deleteStudents(std::vector<Student*>& students);
void menu(std::vector<Student*>& students);

int main() {
	std::vector<Student*> students = loadStudents();
	menu(students);
	return 0;
} // end main

std::vector<Student*> loadStudents() {
	std::vector<Student*> studentList;
	std::ifstream inFile;
	std::string currentLine;

	inFile.open("students.csv"); //open students.csv
	while (getline(inFile, currentLine)) {
		Student* currentStudent = new Student();
		currentStudent->init(currentLine);
		studentList.push_back(currentStudent);
	} // end while loop
	
	return studentList;
} // end readStudentFile

void printStudents(std::vector<Student*> students) {
	std::cout << "_____________________________________________" << std::endl;
	for (Student* currentStudent : students) {
		std::cout << std::endl;
		currentStudent->printStudent();
		std::cout << "_____________________________________________" << std::endl;
	} // end for each loop
} // end printStudents

void printStudentNames(std::vector<Student*> students) {
	std::cout << std::endl;
	for (Student* currentStudent : students) {
		std::cout << currentStudent->getLastFirst() << std::endl;
	} // end for each loop
	std::cout << std::endl;
} // end printStudentNames

void findStudent(std::vector<Student*> students) {
	std::vector<Student*> foundStudents;
	std::stringstream converter;
	std::string searchName;
	std::cout << "Last name of student: ";
	getline(std::cin, searchName);
	for (Student* currentStudent : students) {
		converter.str(currentStudent->getLastFirst());
		std::string lastName;
		getline(converter, lastName, ',');
		if (lastName.find(searchName) != std::string::npos) {
			foundStudents.push_back(currentStudent);
		} // end if
	} // end for each loop
	if (foundStudents.empty() == true) {
		std::cout << "No students found..." << std::endl;
	} else {
		printStudents(foundStudents);
	} // end if
} // end findStudent

void deleteStudents(std::vector<Student*>& students) {
	for (Student* currentStudent : students) {
		delete currentStudent;
	} // end for each loop
} // end deleteStudents

void menu(std::vector<Student*>& students) {
	std::string sInput;
	bool keepGoing = true;
	while (keepGoing) {
		std::cout << "0) Quit" << std::endl << "1) Print all student names" << std::endl << "2) Print all student data" << std::endl << "3) Find a student" << std::endl << std::endl << "Please choose 0-3: " << std::endl;
		getline(std::cin, sInput);
		if (sInput.find("0") != std::string::npos) {
			keepGoing = false;
		} else if (sInput.find("1") != std::string::npos) {
			printStudentNames(students);
		} else if (sInput.find("2") != std::string::npos) {
			printStudents(students);
		} else if (sInput.find("3") != std::string::npos) {
			findStudent(students);
		} else {
			std::cout << "Invalid input..." << std::endl;
		} // end if
	} // end while loop
	deleteStudents(students);
} // end menu
