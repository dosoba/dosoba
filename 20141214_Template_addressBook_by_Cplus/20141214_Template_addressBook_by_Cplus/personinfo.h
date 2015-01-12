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
	
	// 
	~PersonalInfo();

	// overloading operators
	PersonalInfo& operator= (PersonalInfo& info);
	bool operator== (PersonalInfo& info);
	bool operator== (string& info);
	friend ostream& operator<< (ostream& os, PersonalInfo& info);

	// need to definition for accessing private variables
	void setName(string name);
	string getName();
	void setPhone(string name);
	string getPhone();
	void setAddress(string name);
	string getAddress();	
};

#endif /* PERSONINFO_H_ */
