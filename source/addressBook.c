#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addressBook.h"
#include "linkedList.h"


void printMainMenu() {
	printf("1. �ּ������� �Է��Ѵ�.\n");
	printf("2. �ּ������� �����Ѵ�.\n");
	printf("3. �ּ������� �����Ѵ�.\n");
	printf("4. �ּ������� �˻��Ѵ�.\n");
	printf("5. ��ü �ּҷ��� ����Ѵ�.\n");
	printf("6. �ּҷ� ���Ͽ� �����Ѵ�.\n");
	printf("7. �ּҷ� ������ �ҷ��´�.\n");
	printf("0. �����Ѵ�.\n");
}

void print_finish() {
	printf("���α׷��� �����մϴ�.\n");
}

void print_error(int error) {
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

int isEmptyAddressBook(LINKEDLIST *pBook) {
	int isEmpty = TRUE;

	if (pBook->getLengthLinkedList(pBook) > 0) {
		isEmpty = FALSE;
	}

	return isEmpty;
}

void inputPersonInfo(LINKEDLIST *pBook) {
	int index = 0;
	char yesno;
	PERSONALINFO info;

	printf("�̸� : ");
	scanf("%s", info.name);
	printf("��ȭ��ȣ : ");
	scanf("%s", info.phone);
	printf("�ּ� : ");
	scanf("%s", info.address);

	printf("�Էµ� ����\n");
	printHeader(FALSE);
	printPersonInfo(info, FALSE);

	fflush(stdin);
	printf("�߰��Ͻðڽ��ϱ� ? (y/n) :");
	yesno = getchar();

	if (yesno == 'y') {
		pBook->appendLinkedList(pBook, &info);
		printf("�߰��Ǿ����ϴ�.\n");
	}
}

void removePersonInfo(LINKEDLIST *pBook) {
	char name[7];
	int removeIndex = -1;
	char yesno;

	if (isEmptyAddressBook(pBook) == TRUE) {
		print_error(ERROR_EMPTY);
		return;
	}

	printf("������ �̸�: ");
	scanf("%s", name);

	removeIndex = pBook->findNameLinkedList(pBook, name);

	if (removeIndex == -1) {
		print_error(ERROR_NOT_SEARCH);
		return;
	}

	printHeader(FALSE);
	printPersonInfo(viewAtLinkedList(pBook, removeIndex), FALSE);

	fflush(stdin);
	printf("�����ϰڽ��ϱ�? (y/n) :");
	yesno = getchar();

	if (yesno == 'y') {
		pBook->deleteLinkedList(pBook, removeIndex);
		printf("�����Ǿ����ϴ�.\n");
	}
}

void modifyPersonInfo(LINKEDLIST *pBook) {
	char name[7];
	int modifyIndex = -1;
	char yesno;
	PERSONALINFO info;
	NODE *target;

	if (isEmptyAddressBook(pBook) == TRUE) {
		print_error(ERROR_EMPTY);
		return;
	}

	printf("������ �̸�: ");
	scanf("%s", name);

	modifyIndex = pBook->findNameLinkedList(pBook, name);

	if (modifyIndex == -1) {
		print_error(ERROR_NOT_SEARCH);
		return;
	}

	printHeader(FALSE);
	printPersonInfo(viewAtLinkedList(pBook, modifyIndex), FALSE);

	fflush(stdin);
	printf("�����ϰڽ��ϱ�? (y/n) :");
	yesno = getchar();

	if (yesno == 'y') {
		printf("�̸� : ");
		scanf("%s", info.name);
		printf("��ȭ��ȣ : ");
		scanf("%s", info.phone);
		printf("�ּ� : ");
		scanf("%s", info.address);

		printf("������ ����\n");
		printHeader(FALSE);
		printPersonInfo(info, FALSE);

		target = pBook->getNodeLinkedList(pBook, modifyIndex);

		strcpy(target->info->name, info.name);
		strcpy(target->info->phone, info.phone);
		strcpy(target->info->address, info.address);

		printf("�����Ǿ����ϴ�.\n");
	}
}

void searchPersonInfo(LINKEDLIST *pBook) {
	char name[7];
	int foundIndex = -1;

	if (isEmptyAddressBook(pBook) == TRUE) {
		print_error(ERROR_EMPTY);
		return;
	}

	printf("�˻��� �̸�: ");
	scanf("%s", name);

	foundIndex = pBook->findNameLinkedList(pBook, name);

	if (foundIndex == -1) {
		print_error(ERROR_NOT_SEARCH);
		return;
	}

	printHeader(FALSE);
	printPersonInfo(viewAtLinkedList(pBook, foundIndex), FALSE);
}

void printHeader(int printNum) {
	printf("----------------------------------------------\n");
	if (printNum == TRUE) {
		printf("��ȣ  �̸�     ��ȭ��ȣ      �ּ�\n");
	}
	else {
		printf("�̸�     ��ȭ��ȣ      �ּ�\n");
	}
	printf("----------------------------------------------\n");
}

void printPersonInfo(PERSONALINFO info, int printNum) {
	if (printNum != FALSE) {
		printf("%-4d  %-7s  %-12s  %-50s\n", printNum, info.name, info.phone, info.address);
	}
	else {
		printf("%-8s  %-12s  %-50s\n", info.name, info.phone, info.address);
	}
}

void printPersonInfoPointer(PERSONALINFO *info, int printNum) {
	if (printNum != FALSE) {
		printf("%-4d  %-7s  %-12s  %-50s\n", printNum, info->name, info->phone, info->address);
	}
	else {
		printf("%-8s  %-12s  %-50s\n", info->name, info->phone, info->address);
	}
}

void printAllPersonInfo(LINKEDLIST *pBook) {
	int number = 1;
	NODE *target;

	if (isEmptyAddressBook(pBook) == TRUE) {
		print_error(ERROR_EMPTY);
		return;
	}

	printHeader(TRUE);
	target = pBook->moveFirstLinkedList(pBook);
	while (pBook->isTailLinkedList(pBook) != TRUE) {
		printPersonInfoPointer(target->info, number);
		target = pBook->nextLinkedList(pBook);
		number++;
	}
}

void saveAddressBook(LINKEDLIST *pBook) {
	FILE *fp = NULL;
	int index = 0;
	NODE *target;

	if (isEmptyAddressBook(pBook) == TRUE) {
		print_error(ERROR_EMPTY);
		return;
	}

	fp = fopen("addressbook.dat", "w");

	target = pBook->moveFirstLinkedList(pBook);
	while (pBook->isTailLinkedList(pBook) != TRUE) {
		fprintf(fp, "%s\n", target->info->name);
		fprintf(fp, "%s\n", target->info->phone);
		fprintf(fp, "%s\n", target->info->address);
		target = pBook->nextLinkedList(pBook);
	}

	fclose(fp);
	printf("addressbook.dat ���Ͽ� �����Ͽ����ϴ�.\n");
}

void loadAddressBook(LINKEDLIST *pBook) {
	FILE *fp = NULL;
	PERSONALINFO info;

	pBook->deleteAllLinkedList(pBook);

	fp = fopen("addressbook.dat", "r");

	if (fp == NULL) {
		print_error(ERROR_LOAD_FAIL);
		return;
	}

	while (!feof(fp)) {
		memset(&info, 0x00, sizeof(PERSONALINFO));
		fscanf(fp, "%s", info.name);
		fscanf(fp, "%s", info.phone);
		fscanf(fp, "%s", info.address);

		if (strcmp(info.name, "") == 0) {
			break;
		}
		pBook->appendLinkedList(pBook, &info);
	}

	fclose(fp);
	printf("addressbook.dat ������ �ҷ��Խ��ϴ�.\n");
}

void testSetup(LINKEDLIST *list) {
	int index = 0;
	PERSONALINFO sample[MAX_SIZE] = {
			{ "aaa", "0001112222", "abc" },
			{ "bbb", "0001113333", "abc" },
			{ "ccc", "0001114444", "abc" },
			{ "ddd", "0001115555", "abc" },
			{ "eee", "0001116666", "abc" },
			{ "fff", "0001117777", "abc" },
			{ "ggg", "0001118888", "abc" },
			{ "hhh", "0001119999", "abc" },
			{ "iii", "0001110000", "abc" },
			{ "jjj", "0002220000", "abc" }
	};

	for (index = 0; index < MAX_SIZE; index++) {
		list->appendLinkedList(list, &(sample[index]));
	}
}

void createAddressBook(AddressBook* self) {
	
	self->inputPersonInfo = inputPersonInfo;
	self->removePersonInfo = removePersonInfo;
	self->modifyPersonInfo = modifyPersonInfo;
	self->searchPersonInfo = searchPersonInfo;
	self->printAllPersonInfo = printAllPersonInfo;

	self->isEmptyAddressBook = isEmptyAddressBook;	
	self->printPersonInfo = printPersonInfo;
	self->printPersonInfoPointer = printPersonInfoPointer;
	
	self->saveAddressBook = saveAddressBook;
	self->loadAddressBook = loadAddressBook;	
}

int main(void) {
	int menu = -1;
	LINKEDLIST *book;
	AddressBook *self;

	book = (LINKEDLIST*)malloc(sizeof(LINKEDLIST));
	self = (AddressBook*)malloc(sizeof(AddressBook));

	createLinkedList(book);
	createAddressBook(self);

	testSetup(book);

	while (menu != 0) {
		printMainMenu();

		printf("menu: ");
		scanf("%d", &menu);
		fflush(stdin);

		switch (menu) {
		case MENU_INPUT:
			self->inputPersonInfo(book);
			break;
		case MENU_REMOVE:
			self->removePersonInfo(book);
			break;
		case MENU_MODIFY:
			self->modifyPersonInfo(book);
			break;
		case MENU_SEARCH:
			self->searchPersonInfo(book);
			break;
		case MENU_ALL_PRINT:
			self->printAllPersonInfo(book);
			break;
		case MENU_SAVE:
			self->saveAddressBook(book);
			break;
		case MENU_LOAD:
			self->loadAddressBook(book);
			break;
		case MENU_FINISH:
			print_finish();
			break;
		default:
			print_error(ERROR_NO_MENU);
			break;
		}
		if (menu != MENU_FINISH) {
			fflush(stdin);
			printf("\nmenu ȭ������ ���ư��ϴ�. (�ƹ�Ű�� ��������)\n");
			getchar();
		}
	}
	return EXIT_SUCCESS;
}