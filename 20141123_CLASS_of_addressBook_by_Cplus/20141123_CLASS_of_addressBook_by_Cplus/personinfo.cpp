/*********************
* Name : personinfo.cpp
* Date : 2014.11.23
* Writer : Sejoong Kim
**********************/

#include <iostream>
#include "personinfo.h"

//default constructor
PersonalInfo::PersonalInfo() {
	name = "";
	phone = "";
	address = "";
}

//copy constructor
PersonalInfo::PersonalInfo(PersonalInfo &info) {
	name = info.name;
	phone = info.phone;
	address = info.address;
}

//overloading operator = 
PersonalInfo& PersonalInfo::operator= (PersonalInfo& info) {
	name = info.name;
	phone = info.phone;
	address = info.address;

	return *this;
}

//overloading operator ==
bool PersonalInfo::operator== (PersonalInfo& info) {
	if (name == info.name) {
		return true;
	}
	else {
		return false;
	}	
}

//overloading operator <<
ostream& PersonalInfo::operator<< (ostream& os) {
	os << name << phone << address;
	return os;
}