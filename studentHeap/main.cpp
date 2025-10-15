#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "date.h"
#include "address.h"
#include "student.h"

std::vector<Student*> readStudentFile();

int main() {
	std::vector<Student*> students = readStudentFile();
	for (Student* currentStudent : students) {
		currentStudent->printStudent();
		std::cout << std::endl;
	}
	return 0;
} // end main

std::vector<Student*> readStudentFile () {
	std::vector<Student*> studentList;
	std::ifstream inFile;
	std::string currentLine;

	inFile.open("students.csv"); //open students.csv
	while(getline(inFile, currentLine)) {
		Student* currentStudent = new Student();
		currentStudent->init(currentLine);
		studentList.push_back(currentStudent);
	} // end while loop
	
	return studentList;
} // end readStudentFile
