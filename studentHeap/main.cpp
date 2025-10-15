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

int main() {
	std::vector<Student*> students = loadStudents();
	printStudents(students);
	return 0;
} // end main

std::vector<Student*> loadStudents() {
	std::vector<Student*> studentList;
	std::ifstream inFile;
	std::string currentLine;

	inFile.open("students.csv"); //open students.csv
	while(getline(inFile, currentLine)) {
		std::cout << "[" << currentLine << "]" << std::endl;
		Student* currentStudent = new Student();
		currentStudent->init(currentLine);
		studentList.push_back(currentStudent);
	} // end while loop
	
	return studentList;
} // end readStudentFile

void printStudents(std::vector<Student*> students) {
	for(Student* currentStudent : students) {
		std::cout << std::endl;
		currentStudent->printStudent();
		std::cout << "_____________________________________________" << std::endl;
	} // end for each loop
} // end printStudents

void printStudentNames(std::vector<Student*> students) {
	std::cout << std::endl;
	for(Student* currentStudent : students) {
		std::cout << currentStudent->getLastFirst() << std::endl;
	} // end for each loop
	std::cout << std::endl;
} // end printStudentNames
