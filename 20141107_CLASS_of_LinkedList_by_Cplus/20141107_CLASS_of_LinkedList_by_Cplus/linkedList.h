/*********************
* Name : linkedlist.h
* Date : 2014.11.16
* Writer : Sejoong Kim
**********************/

#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#define USE 1
#define NOT_USE 0

#define TRUE 1
#define FALSE 0

#include "personinfo.h"

typedef struct _tag_NODE NODE;

typedef struct _tag_NODE {
	PERSONALINFO *info;
	NODE *next;
} NODE;

class List {
private:
	NODE *head;
	NODE *tail;
	NODE *pos;
	int length;
public:
	List();
	~List();
	void appendLinkedList(PERSONALINFO*);
	NODE* moveToBeforeNodeLinkedList(int);
	void insertLinkedList(int, PERSONALINFO*);
	void deleteLinkedList(int);
	void deleteAllLinkedList();
	PERSONALINFO viewAtLinkedList(int);
	NODE* moveFirstLinkedList();
	NODE* moveLastLinkedList();
	NODE* nextLinkedList();
	int isTailLinkedList();
	int getLengthLinkedList();
	NODE* getNodeLinkedList(int);
	int findNameLinkedList(char*);
	void printLinedList();
};

#endif // __LINKEDLIST__
