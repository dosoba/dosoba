/*********************
* Name : personinfo.cpp
* Date : 2014.11.23
* Writer : Sejoong Kim
**********************/

#include <iostream>
#include <iomanip>
#include "personinfo.h"

//default constructor
PersonalInfo::PersonalInfo() {
	this->name = "";
	this->phone = "";
	this->address = "";
}

//copy constructor
PersonalInfo::PersonalInfo(PersonalInfo &info) {
	this->name = info.name;
	this->phone = info.phone;
	this->address = info.address;
}

// destructor
PersonalInfo::~PersonalInfo() {
	this->_name = "";
	this->_phone = "";
	this->_address = "";
}

//overloading operator = 
PersonalInfo& PersonalInfo::operator= (PersonalInfo& info) {
	this->name = info.name;
	this->phone = info.phone;
	this->address = info.address;

	return *this;
}

//overloading operator ==
bool PersonalInfo::operator== (PersonalInfo& info) {
	if (this->name == info.name) {
		return true;
	}
	else {
		return false;
	}	
}

//overloading operator ==
bool PersonalInfo::operator== (string& info) {
	if (this->name == info) {
		return true;
	}
	else {
		return false;
	}
}

//overloading operator <<
/*
ostream& PersonalInfo::operator<< (ostream& os) {
	os << os.width(8) << left << name << "  ";
	os << os.width(12) << left << phone << "  ";
	os << os.width(50) << left << address;
	return os;
}
*/

//overloading operator <<
ostream& operator<< (ostream& os, PersonalInfo& info) {
	/*
	os.width(8);
	os << left << info.name << "  ";
	os.width(12);
	os << left << info.phone << "  ";
	os.width(50);
	os << left << info.address;
	*/
	os << setw(8) << left << info.name << "  ";
	os << setw(12) << left << info.phone << "  ";
	os << setw(50) << left << info.address;

	return os;
}

// need to definition for accessing private variables
void PersonalInfo::setName(string name) {
	this->name = name;
}

string PersonalInfo::getName() {
	return this->name;
}

void PersonalInfo::setPhone(string phone) {
	this->phone = phone;
}

string PersonalInfo::getPhone() {
	return this->phone;
}

void PersonalInfo::setAddress(string address) {
	this->address = address;
}

string PersonalInfo::getAddress() {
	return this->address;
}
