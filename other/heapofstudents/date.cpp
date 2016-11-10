//date.cpp
#include <iostream>
#include "date.h"
using namespace std;
//implimentation of the date.h prototype

	Date::Date(){
		day = "22";
		month = "April";
		year = "1993";	
	}

	Date::Date(string day, string month, string year){
		Date::day = day;
		Date::month = month;
		Date::year = year;
	}

	void Date::setDate(string day, string month, string year){		
		Date::day = day;
		Date::month = month;
		Date::year = year;
	}

	string Date::getDate(){
		return day + "/" + month + "/" + year;
	}

	void Date::setDay(string day){
		Date::day = day;
	}

	string Date::getDay(){
		return Date::day;
	}
	void Date::setMonth(string month){
		Date::month = month;
	}

	string Date::getMonth(){
		return Date::month;
	}
	void Date::setYear(string year){
		Date::year = year;
	}

	string Date::getYear(){
		return Date::year;
	}
	