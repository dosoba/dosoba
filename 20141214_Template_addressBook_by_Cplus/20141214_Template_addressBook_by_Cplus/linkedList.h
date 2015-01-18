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
#include <iostream>

template <class Type>
class Node {
public:
	Type *info;
	Node *next;
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
	void append(Type &data);
	Node<Type>* moveToBeforeNode(int index);
	void insert(int index, Type &data);
	void erase(int index);
	void eraseAll();
	Type viewAt(int index);
	Node<Type>* moveFirst();
	Node<Type>* moveLast();
	Node<Type>* moveNext();
	int isTail();
	int getLength();
	Node<Type>* getNode(int index);
	//int findName(string);
	int find(Type &data);
	void print();
};

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
void List<Type>::append(Type &data) {
	Node<Type> *last = this->moveLast();
	Node<Type> *newNode = new Node<Type>;

	newNode->info = new Type(data);

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
void List<Type>::insert(int index, Type &data) {
	Node<Type> *target;
	Node<Type> *newNode = new Node<Type>;

	target = this->moveToBeforeNode(index);

	newNode->info = new Type(data);

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
	Node<Type> *target;

	target = this->moveToBeforeNode(index)->next;

	this->pos = target;
	return *(target->info);;
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
int List<Type>::find(Type & data) {
	int index = 0;
	int isFound = FALSE;

	this->moveFirst();
	while (this->isTail() != TRUE) {
		if (*(this->pos->info) == data) {
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
