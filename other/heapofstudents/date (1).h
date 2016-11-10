//date.h

//date class header file

#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <iostream>
#include <string>
using namespace std;

class Date{
	private://private member data for the date class, for both birth date and completion date can use this receipe
		string day;
		string month;
		string year;

	public://constructors and public functionallity of the date class, essentially just getters and setters
		Date();
		Date(string, string, string);

		void setDate(string, string, string);
		string getDate();

		void setDay(string);
		string getDay();
		void setMonth(string);
		string getMonth();
		void setYear(string);
		string getYear();
};

#endif