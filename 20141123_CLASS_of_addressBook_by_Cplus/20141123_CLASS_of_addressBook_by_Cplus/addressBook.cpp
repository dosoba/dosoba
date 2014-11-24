/*********************
* Name : addressBook.cpp
* Date : 2014.11.23
* Writer : Sejoong Kim
**********************/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "addressbook.h"

using namespace std;

AddressBook::AddressBook() {
	this->list = new List;
}

AddressBook::~AddressBook() {
	delete this->list;
}

void AddressBook::printMainMenu() {
	cout << "1. �ּ������� �Է��Ѵ�." << endl;
	cout << "2. �ּ������� �����Ѵ�." << endl;
	cout << "3. �ּ������� �����Ѵ�." << endl;
	cout << "4. �ּ������� �˻��Ѵ�." << endl;
	cout << "5. ��ü �ּҷ��� ����Ѵ�." << endl;
	cout << "6. �ּҷ� ���Ͽ� �����Ѵ�." << endl;
	cout << "7. �ּҷ� ������ �ҷ��´�." << endl;
	cout << "0. �����Ѵ�." << endl;
}

void AddressBook::print_finish() {
	cout << "���α׷��� �����մϴ�." << endl;
}

void AddressBook::print_error(int error) {
	switch (error) {
	case ERROR_NO_MENU:
		cout << "���� ��ȣ�� �Է��Ͽ����ϴ�." << endl;
		break;
	case ERROR_FULL:
		cout << "�ּҷ��� ���� á���ϴ�." << endl;
		break;
	case ERROR_EMPTY:
		cout << "�ּҷ��� ����ֽ��ϴ�." << endl;
		break;
	case ERROR_NOT_SEARCH:
		cout << "�ּ������� ã�� �� �����ϴ�." << endl;
		break;
	case ERROR_LOAD_FAIL:
		cout << "addressbook.book ������ �ҷ��ü� �����ϴ�." << endl;
		break;
	default:
		break;
	}
}

int AddressBook::isEmpty() {
	int isEmpty = TRUE;

	if ( this->list->getLength() > 0) {
		isEmpty = FALSE;
	}

	return isEmpty;
}

void AddressBook::input() {
	PersonalInfo info;
	char yesno;

	cout << "�̸� : ";
	cin >> info.name;
	cout << "��ȭ��ȣ : ";
	cin >> info.phone;
	cout << "�ּ� : ";
	cin >> info.address;

	cout << "�Էµ� ����" << endl;
	this->printHeader(FALSE);
	this->printPersonInfo(info, FALSE);

	cin.sync();
	cout << "�߰��Ͻðڽ��ϱ� ? (y/n) :";
	cin.get(yesno);
	
	if (yesno == 'y') {
		this->list->append(info);
		cout << "�߰��Ǿ����ϴ�." << endl;
	}
}

void AddressBook::remove() {
	string name;
	int removeIndex = -1;
	char yesno;

	if (this->isEmpty() == TRUE) {
		this->print_error(ERROR_EMPTY);
		return;
	}

	cout << "������ �̸�: ";
	cin >> name;

	removeIndex = this->list->findName(name);

	if (removeIndex == -1) {
		this->print_error(ERROR_NOT_SEARCH);
		return;
	}

	this->printHeader(FALSE);
	this->printPersonInfo(this->list->viewAt(removeIndex), FALSE);

	cin.sync();
	cout << "�����ϰڽ��ϱ�? (y/n) :";
	cin.get(yesno);


	if (yesno == 'y') {
		this->list->erase(removeIndex);
		cout << "�����Ǿ����ϴ�." << endl;
	}
}

void AddressBook::modify() {
	string name;
	int modifyIndex = -1;
	char yesno;
	PersonalInfo info;
	Node *target;

	if (this->isEmpty() == TRUE) {
		this->print_error(ERROR_EMPTY);
		return;
	}

	cout << "������ �̸�: ";
	cin >> name;

	modifyIndex = this->list->findName(name);

	if (modifyIndex == -1) {
		this->print_error(ERROR_NOT_SEARCH);
		return;
	}

	this->printHeader(FALSE);
	this->printPersonInfo(this->list->viewAt(modifyIndex), FALSE);

	cin.sync();
	cout << "�����ϰڽ��ϱ�? (y/n) :";
	cin.get(yesno);

	if (yesno == 'y') {
		cout << "�̸� : ";
		cin >> info.name;
		cout << "��ȭ��ȣ : ";
		cin >> info.phone;
		cout << "�ּ� : ";
		cin >> info.address;

		cout << "������ ����\n";
		this->printHeader(FALSE);
		this->printPersonInfo(info, FALSE);

		target = this->list->getNode(modifyIndex);

		target->info->name = info.name;
		target->info->phone = info.phone;
		target->info->address = info.address;

		cout << "�����Ǿ����ϴ�." << endl;
	}
}

void AddressBook::search() {
	string name;
	int foundIndex = -1;

	if (this->isEmpty() == TRUE) {
		this->print_error(ERROR_EMPTY);
		return;
	}

	cout << "�˻��� �̸�: ";
	cin >> name;

	foundIndex = this->list->findName(name);

	if (foundIndex == -1) {
		this->print_error(ERROR_NOT_SEARCH);
		return;
	}

	this->printHeader(FALSE);
	this->printPersonInfo(this->list->viewAt(foundIndex), FALSE);
}

void AddressBook::printHeader(int printNum) {
	cout << "----------------------------------------------" << endl;
	if (printNum == TRUE) {
		cout << "��ȣ  �̸�     ��ȭ��ȣ      �ּ�" << endl;
	}
	else {
		cout << "�̸�     ��ȭ��ȣ      �ּ�" << endl;
	}
	cout << "----------------------------------------------" << endl;
}

void AddressBook::printPersonInfo(PersonalInfo &info, int printNum) {
	if (printNum != FALSE) {
		cout.width(4);
		cout << left << printNum;
		cout << "  ";
		
		cout.width(7);
		cout << left << info.name;
		cout << "  ";

		cout.width(12);
		cout << left << info.phone;
		cout << "  ";

		cout.width(50);
		cout << left << info.address;
		cout << endl;
	}
	else {
		cout.width(8);
		cout << left << info.name;
		cout << "  ";

		cout.width(12);
		cout << left << info.phone;
		cout << "  ";

		cout.width(50);
		cout << left << info.address;
		cout << endl;
	}
}

void AddressBook::printPersonInfoPointer(PersonalInfo *info, int printNum) {
	if (printNum != FALSE) {
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
		cout << left << info->address;
		cout << endl;
	}
	else {
		cout.width(8);
		cout << left << info->name;
		cout << "  ";

		cout.width(12);
		cout << left << info->phone;
		cout << "  ";

		cout.width(50);
		cout << left << info->address;
		cout << endl;
	}
}

void AddressBook::printAll() {
	int number = 1;
	Node *target;

	if (this->isEmpty() == TRUE) {
		this->print_error(ERROR_EMPTY);
		return;
	}

	this->printHeader(TRUE);
	target = this->list->moveFirst();
	while (this->list->isTail() != TRUE) {
		this->printPersonInfoPointer(target->info, number);
		target = this->list->moveNext();
		number++;
	}
}

void AddressBook::save() {
	ofstream file;
	Node *target;

	if (this->isEmpty() == TRUE) {
		this->print_error(ERROR_EMPTY);
		return;
	}

	file.open("addressbook.dat", ios::out);

	target = this->list->moveFirst();

	if (file.is_open()) {
		while (this->list->isTail() != TRUE) {
			file << target->info->name << endl;			
			file << target->info->phone << endl;
			file << target->info->address << endl;
			target = this->list->moveNext();
		}
		file.close();
	}

	//�Ʒ� �ڵ尡 �ʿ����� Ȯ���� �ʿ��ϴ�.
	target = nullptr;

	cout << "addressbook.dat ���Ͽ� �����Ͽ����ϴ�." << endl;
}

void AddressBook::load() {
	ifstream file;
	PersonalInfo info;

	this->list->eraseAll();
	
	file.open("addressbook.dat", ios::in);

	if (!file.is_open()) {
		this->print_error(ERROR_LOAD_FAIL);
		return;
	}

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, info.name);
			getline(file, info.phone);
			getline(file, info.address);

			if (info.name == "") {
				file.close();
				break;
			}
			this->list->append(info);
		}
		file.close();
	}

	cout << "addressbook.dat ������ �ҷ��Խ��ϴ�." << endl;
}

void AddressBook::testSetup() {
	int index = 0;

	PersonalInfo sample[10] = {
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
	
	for (index = 0; index < 10; index++) {
		this->list->append(sample[index]);
	}
}