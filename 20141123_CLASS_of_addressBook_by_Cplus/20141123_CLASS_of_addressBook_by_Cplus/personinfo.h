/*********************
* Name : personinfo.h
* Date : 2014.11.16
* Writer : Sejoong Kim
**********************/

#ifndef PERSONINFO_H_
#define PERSONINFO_H_

#include <string>

using namespace std;

class PersonalInfo {
public:
	string name;
	string phone;
	string address;
public:
	// default constructor
	PersonalInfo();

	// copy constructor
	PersonalInfo(PersonalInfo &info);

	// overloading operators
	PersonalInfo& operator= (PersonalInfo& info);
	bool operator== (PersonalInfo& info);
	bool operator== (string& info);
	ostream& operator<< (ostream& os);
};

#endif /* PERSONINFO_H_ */
