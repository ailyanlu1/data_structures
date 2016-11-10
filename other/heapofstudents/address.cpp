//address.cpp

#include <iostream>
#include <string>
#include "address.h"
//implimentation of the address.h prototype
using namespace std;
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


//added default constructor with street 2
//added perameters of non null constructor with respect to street2
//added getter and setter for street2
