//student class header file
//prototyped class
//recognize dependency upon date.h and address.h
//recognize <string> was added to both prior classes, it is free of charge to use now
//after importing their classes

#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include <iostream>
#include <fstream>
#include "date.h"
#include "address.h"
using namespace std;

class Student{
	private:
		Student *studentInfo;
		Student student(string,string,string,string,string,string,string,string,string,string,string,string,string,string);
		ifstream studentData;
		string fName;
		string lName;
		string gpa;
		string hCompleted;
		Address studAddress;
		Date studbDate;
		Date studcDate;

	public:
		//getter,setter,constructors
		Student();
		Student(string,string,string,string,string,string,string,string,string,string,string,string,string,string,string);

		void setStudent(string,string,string,string,string,string,string,string,string,string,string,string,string,string, string);
		void report();
		
		//void nameReport();
		string nameReport();
		
		void setfName(string);
		string getfName();
		
		void setlName(string);
		string getlName();
		
		void setGpa(string);
		string getGpa();
		
		void sethCompleted(string);
		string gethCompleted();
		
		void setStudAddress(string);
		string getStudAddress();
		
		void setStudbDate(string);
		string getStudbDate();
		
		void setStudcDate(string); 
		string getStudcDate();		
};

#endif
//extended Student non null perameters +1 string
//extended setStudent +1 string
