//student.cpp

#include <iostream>
#include <string>
#include "student.h"
#include "date.h"
#include "address.h"
using namespace std;

	Student::Student(){
		fName = "Blake";
		lName = "Conrad";
		gpa = "4.0";
		hCompleted = "120";
	}
	
	Student::Student(string fName,string lName,string gpa,string hCompleted,string street, string street2, string city,string state,string zip,string bDay,string bMonth,string bYear, string cDay, string cMonth, string cYear){
		Student::fName = fName;
		Student::lName = lName;
		Student::gpa = gpa;
		Student::hCompleted = hCompleted;

		studAddress.setStreet(street);
		studAddress.setStreet2(street2);
		studAddress.setCity(city);
		studAddress.setState(state);
		studAddress.setZip(zip);
		
		studbDate.setDate(bDay, bMonth, bYear);

		studcDate.setDate(cDay, cMonth, cYear);
		
	}

	void Student::setStudent(string fName,string lName,string gpa,string hCompleted,string street, string street2, string city,string state,string zip,string bDay,string bMonth,string bYear, string cDay, string cMonth, string cYear){
		Student::fName = fName;
		Student::lName = lName;
		Student::gpa = gpa;
		Student::hCompleted = hCompleted;

		studAddress.setStreet(street);
		studAddress.setStreet2(street2);
		studAddress.setCity(city);
		studAddress.setState(state);
		studAddress.setZip(zip);
		
		studbDate.setDate(bDay, bMonth, bYear);

		studcDate.setDate(cDay, cMonth, cYear);
	}

	void Student::report(){
		cout << "Name: " << Student::fName << " " << Student::lName << endl << "GPA AND HOURS COMPLETED: " << Student::gpa << "," << Student::hCompleted << endl << "Address: " << Student::studAddress.getAddress() << endl << "Student Date of Birth, Date of Gradution: " << Student::studbDate.getDate() << "," << Student::studcDate.getDate() << endl;
	}

	/*void Student::nameReport(){
		cout << Student::fName << "," << Student::lName << endl;
	}*/
	string Student::nameReport(){
		string fullName = "Name: " + fName + " " + lName;
		return fullName;
	}

	void Student::setfName(string fName){
		Student::fName = fName;
	}
	string Student::getfName(){
		return Student::fName;
	}
	void Student::setlName(string lName){
		Student::lName = lName;
	}
	string Student::getlName(){
		return Student::lName;
	}
	void Student::setGpa(string gpa){
		Student::gpa = gpa;
	}
	string Student::getGpa(){
		return Student::gpa;
	}
	void Student::sethCompleted(string hCompleted){
		Student::hCompleted = hCompleted;
	}
	string Student::gethCompleted(){
		return Student::hCompleted = hCompleted;
	}
	//void Student::setStudAddress(string studAddress){
	//	Student::studAddress = studAddress;
	//}
	string Student::getStudAddress(){
		return Student::studAddress.getAddress();
	}
	//void Student::setStudbDate(string studbDate){
	//	Student::studbDate = studbDate;
	//}
	string Student::getStudbDate(){
		return Student::studbDate.getDate();
	} 
	//void Student::setStudcDate(string studcDate){
	//	Student::studcDate = studcDate;
	//}
	string Student::getStudcDate(){
		return Student::studcDate.getDate();
	}

//updated student non null constructor and setter 