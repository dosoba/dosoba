/*********************
* Name : addressBook.h
* Date : 2014.12.14
* Writer : Sejoong Kim
**********************/

#ifndef ADDRESSBOOK_H_
#define ADDRESSBOOK_H_

#include "personinfo.h"
#include "linkedList.h"

#define MENU_INPUT 1
#define MENU_REMOVE 2
#define MENU_MODIFY 3
#define MENU_SEARCH 4
#define MENU_ALL_PRINT 5
#define MENU_SAVE 6
#define MENU_LOAD 7
#define MENU_FINISH 0

#define ERROR_NO_MENU 1
#define ERROR_FULL 2
#define ERROR_EMPTY 3
#define ERROR_NOT_SEARCH 4
#define ERROR_LOAD_FAIL 5

#define TRUE 1
#define FALSE 0

class AddressBook {
private:
	List<PersonalInfo> *list;
public:
	AddressBook();
	~AddressBook();
	void printMainMenu();
	void print_finish();
	void print_error(int error);
	int isEmpty();
	void input();
	void remove();
	void modify();
	void search();
	void printHeader(int printNum);
	void printPersonInfo(PersonalInfo &info, int printNum);
	void printPersonInfoPointer(PersonalInfo *info, int printNum);
	void printAll();
	void save();
	void load();
	void testSetup();
};
#endif /* ADDRESSBOOK_H_ */
