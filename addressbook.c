#define  _CRT_SECURE_NO_WARNINGS
/*
 * addressbook.c
 *
 *  Created on: 2014. 11. 7.
 *      Author: suandkyu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addressbook.h"

void createAddressBook(ADDRESSBOOK *self) {
	self->list = (LINKEDLIST*)malloc(sizeof(LINKEDLIST));

	createLinkedList(self->list);

	self->printMainMenu = *printMainMenu;
	self->print_finish = *print_finish;
	self->print_error = *print_error;
	self->isEmptyAddressBook = *isEmptyAddressBook;
	self->inputPersonInfo = *inputPersonInfo;
	self->removePersonInfo = *removePersonInfo;
	self->modifyPersonInfo = *modifyPersonInfo;
	self->searchPersonInfo = *searchPersonInfo;
	self->printHeader = *printHeader;
	self->printPersonInfo = *printPersonInfo;
	self->printPersonInfoPointer = *printPersonInfoPointer;
	self->printAllPersonInfo = *printAllPersonInfo;
	self->saveAddressBook = *saveAddressBook;
	self->loadAddressBook = *loadAddressBook;
	self->testSetup = *testSetup;
}

void destroyAddressBook(ADDRESSBOOK *self) {
	destroyLinkedList(self->list);

	free(self->list);
}

void printMainMenu(ADDRESSBOOK *self) {
	printf("1. �ּ������� �Է��Ѵ�.\n");
	printf("2. �ּ������� �����Ѵ�.\n");
	printf("3. �ּ������� �����Ѵ�.\n");
	printf("4. �ּ������� �˻��Ѵ�.\n");
	printf("5. ��ü �ּҷ��� ����Ѵ�.\n");
	printf("6. �ּҷ� ���Ͽ� �����Ѵ�.\n");
	printf("7. �ּҷ� ������ �ҷ��´�.\n");
	printf("0. �����Ѵ�.\n");
}

void print_finish(ADDRESSBOOK *self) {
	printf("���α׷��� �����մϴ�.\n");
}

void print_error(ADDRESSBOOK *self, int error) {
	switch (error) {
	case ERROR_NO_MENU:
		printf("���� ��ȣ�� �Է��Ͽ����ϴ�.\n");
		break;
	case ERROR_FULL:
		printf("�ּҷ��� ���� á���ϴ�.\n");
		break;
	case ERROR_EMPTY:
		printf("�ּҷ��� ����ֽ��ϴ�.\n");
		break;
	case ERROR_NOT_SEARCH:
		printf("�ּ������� ã�� �� �����ϴ�.\n");
		break;
	case ERROR_LOAD_FAIL:
		printf("addressbook.book ������ �ҷ��ü� �����ϴ�.\n");
		break;
	default:
		break;
	}
}

int isEmptyAddressBook(ADDRESSBOOK *self) {
	int isEmpty = TRUE;

	if ( self->list->getLengthLinkedList(self->list) > 0 ) {
		isEmpty = FALSE;
	}

	return isEmpty;
}

void inputPersonInfo(ADDRESSBOOK *self) {
	PERSONALINFO info;
	char yesno;

	printf("�̸� : ");
	scanf("%s", info.name);
	printf("��ȭ��ȣ : ");
	scanf("%s", info.phone);
	printf("�ּ� : ");
	scanf("%s", info.address);

	printf("�Էµ� ����\n");
	self->printHeader(self, FALSE);
	self->printPersonInfo(self, info, FALSE);

	fflush(stdin);
	printf("�߰��Ͻðڽ��ϱ� ? (y/n) :");
	yesno = getchar();

	if ( yesno == 'y' ) {
		self->list->appendLinkedList(self->list, &info);
		printf("�߰��Ǿ����ϴ�.\n");
	}
}

void removePersonInfo(ADDRESSBOOK *self) {
	char name[7];
	int removeIndex = -1;
	char yesno;

	if ( self->isEmptyAddressBook(self) == TRUE ) {
		self->print_error(self, ERROR_EMPTY);
		return ;
	}

	printf("������ �̸�: ");
	scanf("%s", name);

	removeIndex = self->list->findNameLinkedList(self->list, name);

	if ( removeIndex == -1 ) {
		self->print_error(self, ERROR_NOT_SEARCH);
		return ;
	}

	self->printHeader(self, FALSE);
	self->printPersonInfo(self, self->list->viewAtLinkedList(self->list, removeIndex), FALSE);

	fflush(stdin);
	printf("�����ϰڽ��ϱ�? (y/n) :");
	yesno = getchar();

	if ( yesno == 'y' ) {
		self->list->deleteLinkedList(self->list, removeIndex);
		printf("�����Ǿ����ϴ�.\n");
	}
}

void modifyPersonInfo(ADDRESSBOOK *self) {
	char name[7];
	int modifyIndex = -1;
	char yesno;
	PERSONALINFO info;
	NODE *target;

	if ( self->isEmptyAddressBook(self) == TRUE ) {
		self->print_error(self, ERROR_EMPTY);
		return ;
	}

	printf("������ �̸�: ");
	scanf("%s", name);

	modifyIndex = self->list->findNameLinkedList(self->list, name);

	if ( modifyIndex == -1 ) {
		self->print_error(self, ERROR_NOT_SEARCH);
		return ;
	}

	self->printHeader(self, FALSE);
	self->printPersonInfo(self, self->list->viewAtLinkedList(self->list, modifyIndex), FALSE);

	fflush(stdin);
	printf("�����ϰڽ��ϱ�? (y/n) :");
	yesno = getchar();

	if ( yesno == 'y' ) {
		printf("�̸� : ");
		scanf("%s", info.name);
		printf("��ȭ��ȣ : ");
		scanf("%s", info.phone);
		printf("�ּ� : ");
		scanf("%s", info.address);

		printf("������ ����\n");
		self->printHeader(self, FALSE);
		self->printPersonInfo(self, info, FALSE);

		target = self->list->getNodeLinkedList(self->list, modifyIndex);

		strcpy(target->info->name, info.name);
		strcpy(target->info->phone, info.phone);
		strcpy(target->info->address, info.address);

		printf("�����Ǿ����ϴ�.\n");
	}
}

void searchPersonInfo(ADDRESSBOOK *self) {
	char name[7];
	int foundIndex = -1;

	if ( self->isEmptyAddressBook(self) == TRUE ) {
		self->print_error(self, ERROR_EMPTY);
		return ;
	}

	printf("�˻��� �̸�: ");
	scanf("%s", name);

	foundIndex = self->list->findNameLinkedList(self->list, name);

	if ( foundIndex == -1 ) {
		self->print_error(self, ERROR_NOT_SEARCH);
		return ;
	}

	self->printHeader(self, FALSE);
	self->printPersonInfo(self, self->list->viewAtLinkedList(self->list, foundIndex), FALSE);
}

void printHeader(ADDRESSBOOK *self, int printNum) {
	printf("----------------------------------------------\n");
	if ( printNum == TRUE ) {
		printf("��ȣ  �̸�     ��ȭ��ȣ      �ּ�\n");
	} else {
		printf("�̸�     ��ȭ��ȣ      �ּ�\n");
	}
	printf("----------------------------------------------\n");
}

void printPersonInfo(ADDRESSBOOK *self, PERSONALINFO info, int printNum) {
	if ( printNum != FALSE ) {
		printf("%-4d  %-7s  %-12s  %-50s\n", printNum, info.name, info.phone, info.address);
	} else {
		printf("%-8s  %-12s  %-50s\n", info.name, info.phone, info.address);
	}
}

void printPersonInfoPointer(ADDRESSBOOK *self, PERSONALINFO *info, int printNum) {
	if ( printNum != FALSE ) {
		printf("%-4d  %-7s  %-12s  %-50s\n", printNum, info->name, info->phone, info->address);
	} else {
		printf("%-8s  %-12s  %-50s\n", info->name, info->phone, info->address);
	}
}


void printAllPersonInfo(ADDRESSBOOK *self) {
	int number = 1;
	NODE *target;

	if ( self->isEmptyAddressBook(self) == TRUE ) {
		self->print_error(self, ERROR_EMPTY);
		return ;
	}

	self->printHeader(self, TRUE);
	target = self->list->moveFirstLinkedList(self->list);
	while ( self->list->isTailLinkedList(self->list) != TRUE ) {
		self->printPersonInfoPointer(self, target->info, number);
		target = self->list->nextLinkedList(self->list);
		number++;
	}
}

void saveAddressBook(ADDRESSBOOK *self) {
	FILE *fp = NULL;
	NODE *target;

	if ( self->isEmptyAddressBook(self) == TRUE ) {
		self->print_error(self, ERROR_EMPTY);
		return ;
	}

	fp = fopen("addressbook.dat", "w");

	target = self->list->moveFirstLinkedList(self->list);
	while ( self->list->isTailLinkedList(self->list) != TRUE ) {
		fprintf(fp, "%s\n", target->info->name);
		fprintf(fp, "%s\n", target->info->phone);
		fprintf(fp, "%s\n", target->info->address);
		target = self->list->nextLinkedList(self->list);
	}

	fclose(fp);
	printf("addressbook.dat ���Ͽ� �����Ͽ����ϴ�.\n");
}

void loadAddressBook(ADDRESSBOOK *self) {
	FILE *fp = NULL;
	PERSONALINFO info;

	self->list->deleteAllLinkedList(self->list);

	fp = fopen("addressbook.dat", "r");

	if ( fp == NULL ) {
		self->print_error(self, ERROR_LOAD_FAIL);
		return ;
	}

	while( ! feof(fp) ) {
		memset(&info, 0x00, sizeof(PERSONALINFO));
		fscanf(fp, "%s", info.name);
		fscanf(fp, "%s", info.phone);
		fscanf(fp, "%s", info.address);

		if ( strcmp(info.name, "") ==  0 ) {
			break;
		}
		self->list->appendLinkedList(self->list, &info);
	}

	fclose(fp);
	printf("addressbook.dat ������ �ҷ��Խ��ϴ�.\n");
}

void testSetup(ADDRESSBOOK *self) {
	int index = 0;
	PERSONALINFO sample[10] = {
			{"aaa", "0001112222", "abc"},
			{"bbb", "0001113333", "abc"},
			{"ccc", "0001114444", "abc"},
			{"ddd", "0001115555", "abc"},
			{"eee", "0001116666", "abc"},
			{"fff", "0001117777", "abc"},
			{"ggg", "0001118888", "abc"},
			{"hhh", "0001119999", "abc"},
			{"iii", "0001110000", "abc"},
			{"jjj", "0002220000", "abc"}
	};

	for ( index = 0; index < 10; index++ ) {
		self->list->appendLinkedList(self->list, &(sample[index]));
	}
}
