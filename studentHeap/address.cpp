#include <iostream>

//the header file
#include "address.h"

Address::Address() {
	Address::street = "";
	Address::city = "";
	Address::state = "";
	Address::zip = "";
}

void Address::init(std::string street, std::string city, std::string state, std::string zip) {
	Address::street = street;
	Address::city = city;
	Address::state = state;
	Address::zip = zip;
}

void Address::printAddress() {
	std::cout << street << std::endl << city << " " << state << ", " << zip << std::endl;
}
