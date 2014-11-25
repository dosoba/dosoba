/*********************
* Name : personinfo.cpp
* Date : 2014.11.23
* Writer : Sejoong Kim
**********************/

#include <iostream>
#include "personinfo.h"

PersonalInfo& PersonalInfo::operator= (PersonalInfo& info) {
	name = info.name;
	phone = info.phone;
	address = info.address;

	return *this;
}

bool PersonalInfo::operator== (PersonalInfo& info) {
	if (name == info.name) {
		return true;
	}
	else {
		return false;
	}	
}

ostream& PersonalInfo::operator<< (ostream& os) {
	os << name << phone << address;
	return os;
}