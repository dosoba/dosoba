/*********************
* Name : linkedList.cpp
* Date : 2014.11.16
* Writer : Sejoong Kim
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include "linkedlist.h"
#include <iostream>

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

List::List() {
	this->head = new Node;
	this->tail = new Node;

	this->head->next = this->tail;
	this->tail->next = nullptr;
	this->pos = this->head->next;
	this->length = 0;
}

List::~List() {
	if (this->length > 0) {
		this->eraseAll();
	}

	delete this->head;
	delete this->tail;

	this->pos = nullptr;
	this->length = 0;
}

void List::append(PersonalInfo &info) {
	Node *last = this->moveLast();
	Node *newNode = new Node;

	//newNode->info = new PersonalInfo;
	//newNode->info->name = info.name;
	//newNode->info->phone = info.phone;
	//newNode->info->address = info.address;
	//newNode = info;
	newNode->info = new PersonalInfo(info);
	
	newNode->next = last->next;
	last->next = newNode;

	this->pos = newNode;
	this->length++;

	last = nullptr;
	newNode = nullptr;
}

Node* List::moveToBeforeNode(int index) {
	Node *target;
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

void List::insert(int index, PersonalInfo &info) {
	Node *target;
	Node *newNode = new Node;

	target = this->moveToBeforeNode(index);

	//newNode->info = new PersonalInfo;
	//newNode->info->name = info.name;
	//newNode->info->phone = info.phone;
	//newNode->info->address = info.address;
	//newNode = info;
	newNode->info = new PersonalInfo(info);

	newNode->next = target->next;
	target->next = newNode;
	this->length++;

	this->pos = newNode;

	target = nullptr;
	newNode = nullptr;
}

void List::erase(int index) {
	Node *before;
	Node *target;

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

void List::eraseAll() {

	if (this->length == 0) {
		return;
	}

	while (this->getLength() > 0) {
		this->erase(0);
	}

	this->pos = this->head;
}

PersonalInfo List::viewAt(int index) {
	PersonalInfo info;
	Node *target;

	target = this->moveToBeforeNode(index)->next;

	//info.name = target->info->name;
	//info.phone = target->info->phone;
	//info.address = target->info->address;
	info = *(target->info);

	this->pos = target;
	target = nullptr;
	return info;
}

Node* List::moveFirst() {
	this->pos = this->head->next;

	return this->pos;
}

Node* List::moveLast() {
	Node *target;
	if (this->length <= 0) {
		target = this->head;
	}
	else {
		target = this->moveToBeforeNode(this->length - 1)->next;
	}

	this->pos = target;

	return target;
}

Node* List::moveNext() {
	this->pos = this->pos->next;

	return this->pos;
}

int List::isTail() {
	int isTail = FALSE;

	if (this->pos->next == nullptr) {
		isTail = TRUE;
	}

	return isTail;
}

int List::getLength() {
	return this->length;
}

Node* List::getNode(int index) {
	Node *target;

	target = this->moveToBeforeNode(index)->next;

	return target;
}

int List::findName(string name) {
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
