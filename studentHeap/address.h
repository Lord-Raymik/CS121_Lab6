#ifndef HAS_ADDRESS_H
#define HAS_ADDRESS_H

class Address {
	private:
		std::string street;
		std::string city;
		std::string state;
		std::string zip;
	public:
		Address ();
		void init(std::string street, std::string city, std::string state, std::string zip);
		void printAddress();
};

#endif //HAS_ADDRESS_H
