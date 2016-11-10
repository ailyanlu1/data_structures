//main.cpp

#include <iostream>
#include <fstream>
#include "student.h"
#include <algorithm>
#include <string>
#define SIZE 50

using namespace std;

/* * * * */
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

/* * * * */
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

/* * * * */
Address::Address(){
    street = "3.14 Calculus Court";
    street2 = "Apt B";
    city = "Greenwood";
    state = "IN";
    zip = "46143";
}

Address::Address(string street,string street2, string city, string state, string zip){
    Address::street = street;
    Address::street2 = street2;
    Address::city = city;
    Address::state = state;
    Address::zip = zip;
}

void Address::setAddress(string street, string street2, string city, string state, string zip){
    Address::street = street;
    Address::street2 = street2;
    Address::city = city;
    Address::state = state;
    Address::zip = zip;
}

string Address::getAddress(){
    return street + " " + street2 + " " + city + " " + state + " " + zip;
	
}

void Address::setStreet(string street){
    Address::street = street;
}

string Address::getStreet(){
    return Address::street;
}

void Address::setStreet2(string street2){
    Address::street2 = street2;
}

string Address::getStreet2(){
    return Address::street2;
}

void Address::setCity(string city){
    Address::city = city;
}

string Address::getCity(){
    return Address::city;
}
void Address::setState(string state){
    Address::state = state;
}

string Address::getState(){
    return Address::state;
}
void Address::setZip(string zip){
    Address::zip = zip;
}

string Address::getZip(){
    return Address::zip;
}

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


int main(){
	string *micro;
	Student *studentInfo;
	string *nameArray;
	string text;
	int studentIndex = 0;
				
	
	studentInfo = new Student[SIZE + 1];
	ifstream studentData;
	studentData.open("data.txt");

	while(!studentData.eof()){
		micro = new string[16];
		
		for (int i = 0; i < 16; i++){
			getline(studentData, text, ',');
			micro[i] = text;
		}
		studentInfo[studentIndex].setStudent(micro[1], micro[2], micro[3],micro[4], micro[5], micro[6],micro[7], micro[8], micro[9],micro[10], micro[11], micro[12],micro[13], micro[14], micro[15]);

		studentIndex++;
		delete[] micro;
	}
	

	
	
	cout << endl << endl << "PRESS ENTER TO PRINT STUDENT REPORT" << endl << endl;
	cin.ignore();

	for(int i = 0; i < SIZE; i++){
		studentInfo[i].report();
		cout << endl;
	
	}
	
	cout << endl << endl << "PRESS ENTER TO PRINT STUDENT NAMES INSIDE OF REPORT" << endl << endl;
	cin.ignore();
	
	nameArray = new string[SIZE + 1];
	
	for(int i = 0; i < SIZE; i++){
		cout << studentInfo[i].nameReport() << endl;
		nameArray[i] = studentInfo[i].nameReport();

	}
	

	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			if(nameArray[j] > nameArray[j+1]){
				string temp = nameArray[j];
				nameArray[j] = nameArray[j+1];
				nameArray[j+1] = temp;
			}
		}
		
	}
	
	cout << endl << endl << "STUDENT NAMES ALPHABETIZED" << endl << endl;

	for (int i = 0; i < SIZE+1; i++){
		cout << nameArray[i] << endl;
	}
	
	delete[] nameArray;
	delete[] studentInfo;
	studentData.close();
	return 0;
}

