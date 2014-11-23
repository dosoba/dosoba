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

class Node {
public:
	PersonalInfo *info;
	Node *next;
};

class List {
private:
	Node *head;
	Node *tail;
	Node *pos;
	int length;
public:
	List();
	~List();
	void append(PersonalInfo&);
	Node* moveToBeforeNode(int);
	void insert(int, PersonalInfo&);
	void erase(int);
	void eraseAll();
	PersonalInfo viewAt(int);
	Node* moveFirst();
	Node* moveLast();
	Node* moveNext();
	int isTail();
	int getLength();
	Node* getNode(int);
	int findName(string);
	void print();
};

#endif // __LINKEDLIST__
