#ifndef HAS_STUDENT_H
#define HAS_STUDENT_H

#include "address.h"
#include "date.h"

class Student {
	private:
		std::string firstName;
		std::string lastName;
		Address* address;
		Date* birthday;
		Date* expectedGradDate;
		int creditHoursComplete;
	public:
		Student();
		~Student();
		Date* getBirthday();
		Date* getExpectedGradDate();
		int getCreditHours();
		void init(std::string studentString);
		void printStudent();
		std::string getLastFirst();
};

#endif //HAS_STUDENT_H
