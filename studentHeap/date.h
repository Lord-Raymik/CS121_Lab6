#ifndef HAS_DATE_H
#define HAS_DATE_H

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

#endif //HAS_DATE_H
