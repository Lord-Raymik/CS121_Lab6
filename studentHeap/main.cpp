#include <iostream>
#include "date.cpp"
#include "address.cpp"
#include "student.h"

void testAddress();
void testDate();
void testStudent();

int main(){
  std::cout << "Beginning Test..." << std::endl;

  testAddress();
  testDate();

  return 0;
} // end main

void testAddress() {
	Address a;
	a.init("123 W Main St", "Muncie", "IN", "47303");
	a.printAddress();
}

void testDate() {
	Date d;
	d.init("6/28/2005");
	d.printDate();
}
