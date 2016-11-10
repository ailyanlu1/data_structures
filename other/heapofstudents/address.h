//address class header file

#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS

#include <iostream>
#include <string>
using namespace std;

class Address{
	private://private data members for address class
		string street;
		string street2;
		string city;
		string state;
		string zip;
	public://constructors and public methods, essentially setters and getters for longterm project if this code was used
		Address();
		Address(string,string, string, string, string);

		void setAddress(string,string, string, string, string);
		string getAddress();

		void setStreet(string);
		string getStreet();
		void setStreet2(string);
		string getStreet2();
		void setCity(string);
		string getCity();
		void setState(string);
		string getState();
		void setZip(string);
		string getZip();	
};
//added street2 private data member and setter and getter
#endif
