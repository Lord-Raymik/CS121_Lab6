#include <iostream>
#include <sstream>
#include <fstream>

class Date {
	private:
		int month;
		int day;
		int year;
	public:
		Date();
		void init(std::string date);
		void printDate();
};
