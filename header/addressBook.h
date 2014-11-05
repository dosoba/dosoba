#ifndef __ADDRESSBOOK__H
#define __ADDRESSBOOK__H

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

#define USE 1
#define NOT_USE 0

#define TRUE 1
#define FALSE 0

#define MAX_SIZE 10

typedef struct ST_LINKEDLIST LINKEDLIST;

/*
typedef struct ST_PERSONALINFO {
	char* name;
	char* phone;
	char* address;
} PERSONALINFO;
*/
typedef struct ST_ADDRESSBOOK {
	void (*inputPersonInfo)(LINKEDLIST*);
	void (*removePersonInfo)(LINKEDLIST*);
	void (*modifyPersonInfo)(LINKEDLIST*);
	void (*searchPersonInfo)(LINKEDLIST*);
	void (*printPersonInfo)(PERSONALINFO, int);
	void (*printAllPersonInfo)(LINKEDLIST*);

	void (*saveAddressBook)(LINKEDLIST*);
	void (*loadAddressBook)(LINKEDLIST*);

	//void (*printMainMenu)();
	//void (*print_finish)();
	//void (*print_error)(int);
	int (*isEmptyAddressBook)(LINKEDLIST*);
	//void (*printHeader)(int);
	void (*printPersonInfoPointer)(PERSONALINFO*, int);
} AddressBook;

void inputPersonInfo(LINKEDLIST *pBook);
void removePersonInfo(LINKEDLIST *pBook);
void modifyPersonInfo(LINKEDLIST *pBook);
void searchPersonInfo(LINKEDLIST *pBook);
void printPersonInfo(PERSONALINFO info, int printNum);
void printAllPersonInfo(LINKEDLIST *pBook);
void saveAddressBook(LINKEDLIST *pBook);
void loadAddressBook(LINKEDLIST *pBook);
int isEmptyAddressBook(LINKEDLIST *pBook);
void printPersonInfoPointer(PERSONALINFO *info, int printNum);

void printMainMenu();
void print_finish();
void print_error(int error);
void printHeader(int printNum);

void testSetup(LINKEDLIST *list);

#endif // __ADDRESSBOOK__H
