#ifndef __ADDRESSBOOK__
#define __ADDRESSBOOK__

void inputPersonInfo(LINKEDLIST *pBook);
void removePersonInfo(PERSONALINFO *pBook);
void modifyPersonInfo(PERSONALINFO *pBook);
void searchPersonInfo(LINKEDLIST *pBook);
void printPersonInfo(PERSONALINFO info, int printNum);
void printAllPersonInfo(PERSONALINFO *pBook);

void saveAddressBook(LINKEDLIST *pBook);
void loadAddressBook(LINKEDLIST *pBook);

void printMainMenu();
void print_finish();
void print_error(int error);
int isEmptyAddressBook(LINKEDLIST *pBook);
void printHeader(int printNum);
void printPersonInfoPointer(PERSONALINFO *info, int printNum);

void testSetup(LINKEDLIST *list);

#endif // __ADDRESSBOOK__
