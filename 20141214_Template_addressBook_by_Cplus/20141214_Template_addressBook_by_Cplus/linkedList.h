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
#include "linkedlist.h"
#include <iostream>

template <class Type>
class Node {
public:
	PersonalInfo *info;
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

/*********************
* Name : linkedList.cpp
* Date : 2014.12.14
* Writer : Sejoong Kim
**********************/

using namespace std;

/*
//debug
void printHeaderLinkedList(int printNum) {
cout << "----------------------------------------------" << endl;
if (printNum == TRUE) {
cout << "번호  이름     전화번호      주소" << endl;
}
else {
cout << "이름     전화번호      주소" << endl;
}
cout << "----------------------------------------------" << endl;
}

void printPersonInfoLinkedList(PersonalInfo *info, int printNum) {
if (printNum != FALSE) {
//std::cout << "%-4d  %-7s  %-12s  %-50s", printNum, info->name, info->phone, info->address << std::endl;
cout.width(4);
cout << left << printNum;
cout << "  ";
cout.width(7);
cout << left << info->name;
cout << "  ";
cout.width(12);
cout << left << info->phone;
cout << "  ";
cout.width(50);
cout << left << info->address << endl;
}
else {
//printf("%-8s  %-12s  %-50s\n", info->name, info->phone, info->address);
cout.width(8);
cout << left << info->name;
cout << "  ";
cout.width(12);
cout << left << info->phone;
cout << "  ";
cout.width(50);
cout << left << info->address << endl;
}
}

void List::print() {
int number = 1;
Node *target;

printHeaderLinkedList(TRUE);

target = this->moveFirst();
while (this->isTail() != TRUE) {
printPersonInfoLinkedList(target->info, number);
target = this->moveNext();
number++;
}
}

int main(void) {
List *list = new List();

PersonalInfo info1 = { "aaa", "0001110000", "xxx" };
PersonalInfo info2 = { "bbb", "0002220000", "yyy" };
PersonalInfo info3 = { "ccc", "0003330000", "zzz" };

list->append(info1);
list->append(info2);
list->insert(1, info3);

list->print();

delete list;

return 0;
}
// debug
*/

template <class Type>
List<Type>::List() {
	this->head = new Node<Type>;
	this->tail = new Node<Type>;

	this->head->next = this->tail;
	this->tail->next = nullptr;
	this->pos = this->head->next;
	this->length = 0;
}

template <class Type>
List<Type>::~List() {
	if (this->length > 0) {
		this->eraseAll();
	}

	delete this->head;
	delete this->tail;

	this->pos = nullptr;
	this->length = 0;
}

template <class Type>
void List<Type>::append(Type &info) {
	Node<Type> *last = this->moveLast();
	Node<Type> *newNode = new Node<Type>;

	//newNode->info = new PersonalInfo;
	//newNode->info->name = info.name;
	//newNode->info->phone = info.phone;
	//newNode->info->address = info.address;
	//newNode = info;
	newNode->info = new Type(info);

	newNode->next = last->next;
	last->next = newNode;

	this->pos = newNode;
	this->length++;

	last = nullptr;
	newNode = nullptr;
}

template <class Type>
Node<Type>* List<Type>::moveToBeforeNode(int index) {
	Node<Type> *target;
	int i = 0;

	if (index <= 0) {
		target = this->head;
	}
	else {
		target = this->moveFirst();
		while (i < index - 1) {
			target = this->moveNext();
			i++;
		}
	}

	return target;
}

template <class Type>
void List<Type>::insert(int index, Type &info) {
	Node<Type> *target;
	Node<Type> *newNode = new Node<Type>;

	target = this->moveToBeforeNode(index);

	//newNode->info = new PersonalInfo;
	//newNode->info->name = info.name;
	//newNode->info->phone = info.phone;
	//newNode->info->address = info.address;
	//newNode = info;
	newNode->info = new Type(info);

	newNode->next = target->next;
	target->next = newNode;
	this->length++;

	this->pos = newNode;

	target = nullptr;
	newNode = nullptr;
}

template <class Type>
void List<Type>::erase(int index) {
	Node<Type> *before;
	Node<Type> *target;

	before = this->moveToBeforeNode(index);

	target = before->next;
	before->next = target->next;

	delete target->info;
	target->next = nullptr;
	delete target;

	this->pos = before;
	this->length--;

	before = nullptr;
	target = nullptr;
}

template <class Type>
void List<Type>::eraseAll() {

	if (this->length == 0) {
		return;
	}

	while (this->getLength() > 0) {
		this->erase(0);
	}

	this->pos = this->head;
}

template <class Type>
Type List<Type>::viewAt(int index) {
	Type info;
	Node<Type> *target;

	target = this->moveToBeforeNode(index)->next;

	//info.name = target->info->name;
	//info.phone = target->info->phone;
	//info.address = target->info->address;
	info = *(target->info);

	this->pos = target;
	target = nullptr;
	return info;
}

template <class Type>
Node<Type>* List<Type>::moveFirst() {
	this->pos = this->head->next;

	return this->pos;
}

template <class Type>
Node<Type>* List<Type>::moveLast() {
	Node<Type> *target;
	if (this->length <= 0) {
		target = this->head;
	}
	else {
		target = this->moveToBeforeNode(this->length - 1)->next;
	}

	this->pos = target;

	return target;
}

template <class Type>
Node<Type>* List<Type>::moveNext() {
	this->pos = this->pos->next;

	return this->pos;
}

template <class Type>
int List<Type>::isTail() {
	int isTail = FALSE;

	if (this->pos->next == nullptr) {
		isTail = TRUE;
	}

	return isTail;
}

template <class Type>
int List<Type>::getLength() {
	return this->length;
}

template <class Type>
Node<Type>* List<Type>::getNode(int index) {
	Node<Type> *target;

	target = this->moveToBeforeNode(index)->next;

	return target;
}

template <class Type>
int List<Type>::findName(string name) {
	int index = 0;
	int isFound = FALSE;

	this->moveFirst();
	while (this->isTail() != TRUE) {
		if (*(this->pos->info) == name) {
			isFound = TRUE;
			break;
		}
		this->moveNext();
		index++;
	}

	if (isFound == FALSE) {
		index = -1;
	}

	return index;
}


#endif // __LINKEDLIST__
