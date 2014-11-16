/*********************
* Name : linkedList.cpp
* Date : 2014.11.16
* Writer : Sejoong Kim
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include "linkedlist.h"
#include <iostream>

using namespace std;

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

void printPersonInfoLinkedList(PERSONALINFO *info, int printNum) {
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

void List::printLinedList() {
	int number = 1;
	NODE *target;

	printHeaderLinkedList(TRUE);

	target = this->moveFirstLinkedList();
	while (this->isTailLinkedList() != TRUE) {
		printPersonInfoLinkedList(target->info, number);
		target = this->nextLinkedList();
		number++;
	}
}

int main(void) {
	List *list = new List();

	PERSONALINFO info1 = { "aaa", "0001110000", "xxx" };
	PERSONALINFO info2 = { "bbb", "0002220000", "yyy" };
	PERSONALINFO info3 = { "ccc", "0003330000", "zzz" };

	list->appendLinkedList(&info1);
	list->appendLinkedList(&info2);
	list->insertLinkedList(1, &info3);

	list->printLinedList();

	delete list;

	return 0;
}
// debug

List::List() {
	this->head = new NODE;
	this->tail = new NODE;

	this->head->next = this->tail;
	this->tail->next = NULL;
	this->pos = this->head->next;
	this->length = 0;
}

List::~List() {
	if (this->length > 0) {
		this->deleteAllLinkedList();
	}

	delete this->head;
	delete this->tail;

	this->pos = NULL;
	this->length = 0;
}

void List::appendLinkedList(PERSONALINFO* p_info) {
	NODE *last = this->moveLastLinkedList();
	NODE *newNode = new NODE;

	newNode->info = new PERSONALINFO;
	strcpy(newNode->info->name, p_info->name);
	strcpy(newNode->info->phone, p_info->phone);
	strcpy(newNode->info->address, p_info->address);
	this->length++;

	newNode->next = last->next;
	last->next = newNode;

	this->pos = newNode;

	last = NULL;
	newNode = NULL;
}

NODE* List::moveToBeforeNodeLinkedList(int index) {
	NODE *target;
	int i = 0;

	if (index <= 0) {
		target = this->head;
	}
	else {
		target = this->moveFirstLinkedList();
		while (i < index - 1) {
			target = this->nextLinkedList();
			i++;
		}
	}

	return target;
}

void List::insertLinkedList(int index, PERSONALINFO* p_info) {
	NODE *target;
	NODE *newNode = new NODE;

	target = this->moveToBeforeNodeLinkedList(index);

	newNode->info = new PERSONALINFO;
	strcpy(newNode->info->name, p_info->name);
	strcpy(newNode->info->phone, p_info->phone);
	strcpy(newNode->info->address, p_info->address);
	this->length++;

	newNode->next = target->next;
	target->next = newNode;

	this->pos = newNode;

	target = NULL;
	newNode = NULL;
}

void List::deleteLinkedList(int index) {
	NODE *before;
	NODE *target;

	before = this->moveToBeforeNodeLinkedList(index);

	target = before->next;
	before->next = target->next;

	delete target->info;
	target->next = NULL;
	delete target;

	this->pos = before;
	this->length--;

	before = NULL;
	target = NULL;
}

void List::deleteAllLinkedList() {

	if (this->length == 0) {
		return;
	}

	while (this->getLengthLinkedList() > 0) {
		this->deleteLinkedList(0);
	}

	this->pos = this->head;
}

PERSONALINFO List::viewAtLinkedList(int index) {
	PERSONALINFO info;
	NODE *target;

	target = this->moveToBeforeNodeLinkedList(index)->next;

	strcpy(info.name, target->info->name);
	strcpy(info.phone, target->info->phone);
	strcpy(info.address, target->info->address);

	this->pos = target;

	target = NULL;

	return info;
}

NODE* List::moveFirstLinkedList() {
	this->pos = this->head->next;

	return this->pos;
}

NODE* List::moveLastLinkedList() {
	NODE *target;
	if (this->length <= 0) {
		target = this->head;
	}
	else {
		target = this->moveToBeforeNodeLinkedList(this->length - 1)->next;
	}

	this->pos = target;

	return target;
}

NODE* List::nextLinkedList() {
	this->pos = this->pos->next;

	return this->pos;
}

int List::isTailLinkedList() {
	int isTail = FALSE;

	if (this->pos->next == NULL) {
		isTail = TRUE;
	}

	return isTail;
}

int List::getLengthLinkedList() {
	return this->length;
}

NODE* List::getNodeLinkedList(int index) {
	NODE *target;

	target = this->moveToBeforeNodeLinkedList(index)->next;

	return target;
}

int List::findNameLinkedList(char* p_name) {
	int index = 0;
	int isFound = FALSE;

	this->moveFirstLinkedList();
	while (this->isTailLinkedList() != TRUE) {
		if (strcmp(this->pos->info->name, p_name) == 0) {
			isFound = TRUE;
			break;
		}
		this->nextLinkedList();
		index++;
	}

	if (isFound == FALSE) {
		index = -1;
	}

	return index;
}
