/*********************
* Name : personinfo.h
* Date : 2014.12.14
* Writer : Sejoong Kim
**********************/

#ifndef PERSONINFO_H_
#define PERSONINFO_H_

#include <string>

using namespace std;

class PersonalInfo {
private:
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
	//ostream& operator<< (ostream& os);
	friend ostream& operator<< (ostream& os, PersonalInfo& info);

	// need to definition for accessing private variables
	void setName(string);
	string getName();
	void setPhone(string);
	string getPhone();
	void setAddress(string);
	string getAddress();	
};

#endif /* PERSONINFO_H_ */
