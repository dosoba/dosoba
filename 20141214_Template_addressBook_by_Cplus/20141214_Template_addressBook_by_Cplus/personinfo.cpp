/*********************
* Name : personinfo.cpp
* Date : 2014.12.14
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

PersonalInfo::~PersonalInfo() {
	this->name = "";
	this->phone = "";
	this->address = "";
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
ostream& operator<< (ostream& os, PersonalInfo& info) {

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
