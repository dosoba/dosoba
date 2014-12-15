/*********************
* Name : linkedlist.h
* Date : 2014.12.14
* Writer : Sejoong Kim
**********************/

#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#define USE 1
#define NOT_USE 0

#define TRUE 1
#define FALSE 0

#include "personinfo.h"

template <class Type>
class Node {
public:
	Type *info;
	Node<Type> *next;
};

template <class Type>
class List {
private:
	Node<Type> *head;
	Node<Type> *tail;
	Node<Type> *pos;
	int length;
public:
	List();
	~List();
	void append(Type&);
	Node<Type>* moveToBeforeNode(int);
	void insert(int, Type&);
	void erase(int);
	void eraseAll();
	Type viewAt(int);
	Node<Type>* moveFirst();
	Node<Type>* moveLast();
	Node<Type>* moveNext();
	int isTail();
	int getLength();
	Node<Type>* getNode(int);
	int findName(string);
	void print();
};

#endif // __LINKEDLIST__
