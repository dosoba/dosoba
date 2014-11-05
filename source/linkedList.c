#define _CRT_SECURE_NO_WARNINGS

#include "addressBook.h"
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG_LINKEDLIST

void printHeaderLinkedList(int printNum) {
	printf("----------------------------------------------\n");
	if (printNum == TRUE) {
		printf("번호  이름     전화번호      주소\n");
	}
	else {
		printf("이름     전화번호      주소\n");
	}
	printf("----------------------------------------------\n");
}

void printPersonInfoLinkedList(PERSONALINFO *info, int printNum) {
	if (printNum != FALSE) {
		printf("%-4d  %-7s  %-12s  %-50s\n", printNum, info->name, info->phone, info->address);
	}
	else {
		printf("%-8s  %-12s  %-50s\n", info->name, info->phone, info->address);
	}
}

void printLinedList(LINKEDLIST *self) {
	int number = 1;
	NODE *target;

	printHeaderLinkedList(TRUE);

	target = moveFirstLinkedList(self);
	while (isTailLinkedList(self) != TRUE) {
		printPersonInfoLinkedList(target->info, number);
		target = nextLinkedList(self);
		number++;
	}
}


int main(void) {
	LINKEDLIST *list;

	PERSONALINFO info1 = { "aaa", "0001110000", "xxx", USE };
	PERSONALINFO info2 = { "bbb", "0002220000", "yyy", USE };
	PERSONALINFO info3 = { "ccc", "0003330000", "zzz", USE };

	list = (LINKEDLIST*)malloc(sizeof(LINKEDLIST));

	createLinkedList(list);

	appendLinkedList(list, &info1);
	appendLinkedList(list, &info2);
	insertLinkedList(list, 1, &info3);

	printLinedList(list);

	destroyLinkedList(list);

	free(list);

	return 0;
}

#endif // DEBUG_LINKEDLIST

void createLinkedList(LINKEDLIST *self) {

	self->head = (NODE*)malloc(sizeof(NODE));
	self->tail = (NODE*)malloc(sizeof(NODE));

	self->head->next = self->tail;
	self->tail->next = NULL;
	self->pos = self->head->next;
	self->length = 0;

	self->appendLinkedList = appendLinkedList;
	self->deleteAllLinkedList = deleteAllLinkedList;
	self->deleteLinkedList = deleteLinkedList;
	self->findNameLinkedList = findNameLinkedList;
	self->getLengthLinkedList = getLengthLinkedList;
	self->getNodeLinkedList = getNodeLinkedList;
	self->insertLinkedList = insertLinkedList;
	self->isTailLinkedList = isTailLinkedList;
	self->moveFirstLinkedList = moveFirstLinkedList;
	self->moveLastLinkedList = moveLastLinkedList;
	self->moveToBeforeNodeLinkedList = moveToBeforeNodeLinkedList;
	self->nextLinkedList = nextLinkedList;
	self->viewAtLinkedList = viewAtLinkedList;
}

void destroyLinkedList(LINKEDLIST *self) {

	if (self->length > 0) {
		self->deleteAllLinkedList(self);
	}

	free(self->head);
	free(self->tail);

	self->pos = NULL;
	self->length = 0;
}

void appendLinkedList(LINKEDLIST *self, PERSONALINFO* p_info) {

	NODE *last = self->moveLastLinkedList(self);
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	newNode->info = (PERSONALINFO*)malloc(sizeof(PERSONALINFO));
	strcpy(newNode->info->name, p_info->name);
	strcpy(newNode->info->phone, p_info->phone);
	strcpy(newNode->info->address, p_info->address);
	self->length++;

	newNode->next = last->next;
	last->next = newNode;

	self->pos = newNode;

	last = NULL;
	newNode = NULL;
}

NODE* moveToBeforeNodeLinkedList(LINKEDLIST *self, int index) {

	NODE *target;
	int i = 0;

	if (index <= 0) {
		target = self->head;
	}
	else {
		target = self->moveFirstLinkedList(self);
		while (i < index - 1) {
			target = self->nextLinkedList(self);
			i++;
		}
	}

	return target;
}

void insertLinkedList(LINKEDLIST *self, int index, PERSONALINFO* p_info) {

	NODE *target;
	NODE *newNode = (NODE*)malloc(sizeof(NODE));

	target = self->moveToBeforeNodeLinkedList(self, index);

	newNode->info = (PERSONALINFO*)malloc(sizeof(PERSONALINFO));
	strcpy(newNode->info->name, p_info->name);
	strcpy(newNode->info->phone, p_info->phone);
	strcpy(newNode->info->address, p_info->address);
	//newNode->info->flag = p_info->flag;
	self->length++;

	newNode->next = target->next;
	target->next = newNode;

	self->pos = newNode;

	target = NULL;
	newNode = NULL;
}

void deleteLinkedList(LINKEDLIST *self, int index) {

	NODE *before;
	NODE *target;

	before = self->moveToBeforeNodeLinkedList(self, index);

	target = before->next;
	before->next = target->next;

	free(target->info);
	target->next = NULL;
	free(target);

	self->pos = before;
	self->length--;

	before = NULL;
	target = NULL;
}

void deleteAllLinkedList(LINKEDLIST *self) {

	if (self->length == 0) {
		return;
	}

	while (getLengthLinkedList(self) > 0) {
		self->deleteLinkedList(self, 0);
	}

	self->pos = self->head;
}

PERSONALINFO viewAtLinkedList(LINKEDLIST *self, int index) {

	PERSONALINFO info;
	NODE *target;

	target = self->moveToBeforeNodeLinkedList(self, index)->next;

	strcpy(info.name, target->info->name);
	strcpy(info.phone, target->info->phone);
	strcpy(info.address, target->info->address);

	self->pos = target;

	target = NULL;

	return info;
}

NODE* moveFirstLinkedList(LINKEDLIST *self) {

	self->pos = self->head->next;

	return self->pos;
}

NODE* moveLastLinkedList(LINKEDLIST *self) {

	NODE *target;
	if (self->length <= 0) {
		target = self->head;
	}
	else {
		target = (self->moveToBeforeNodeLinkedList(self, self->length - 1))->next;
	}

	self->pos = target;

	return target;
}

NODE* nextLinkedList(LINKEDLIST *self) {

	self->pos = self->pos->next;

	return self->pos;
}

int isTailLinkedList(LINKEDLIST *self) {

	int isTail = FALSE;

	if (self->pos->next == NULL) {
		isTail = TRUE;
	}

	return isTail;
}

int getLengthLinkedList(LINKEDLIST *self) {

	return self->length;
}

NODE* getNodeLinkedList(LINKEDLIST *self, int index) {

	NODE *target;

	target = (self->moveToBeforeNodeLinkedList(self, index))->next;

	return target;
}

int findNameLinkedList(LINKEDLIST *self, char* p_name) {

	int index = 0;
	int isFound = FALSE;

	self->moveFirstLinkedList(self);
	while (isTailLinkedList(self) != TRUE) {
		if (strcmp(self->pos->info->name, p_name) == 0) {
			isFound = TRUE;
			break;
		}
		self->nextLinkedList(self);
		index++;
	}

	if (isFound == FALSE) {
		index = -1;
	}

	return index;
}