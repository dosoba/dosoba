/*********************
* Name : addressBook.cpp
* Date : 2014.12.14
* Writer : Sejoong Kim
**********************/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include "addressbook.h"

using namespace std;

template <class Type>
AddressBook<Type>::AddressBook() {
	this->list = new List<Type>;
}

template <class Type>
AddressBook<Type>::~AddressBook() {
	delete this->list;
}

template <class Type>
void AddressBook<Type>::printMainMenu() {
	cout << "1. 주소정보를 입력한다." << endl;
	cout << "2. 주소정보를 삭제한다." << endl;
	cout << "3. 주소정보를 수정한다." << endl;
	cout << "4. 주소정보를 검색한다." << endl;
	cout << "5. 전체 주소록을 출력한다." << endl;
	cout << "6. 주소록 파일에 저장한다." << endl;
	cout << "7. 주소록 파일을 불러온다." << endl;
	cout << "0. 종료한다." << endl;
}

template <class Type>
void AddressBook<Type>::print_finish() {
	cout << "프로그램을 종료합니다." << endl;
}

template <class Type>
void AddressBook<Type>::print_error(int error) {
	switch (error) {
	case ERROR_NO_MENU:
		cout << "없는 번호를 입력하였습니다." << endl;
		break;
	case ERROR_FULL:
		cout << "주소록이 가득 찼습니다." << endl;
		break;
	case ERROR_EMPTY:
		cout << "주소록이 비어있습니다." << endl;
		break;
	case ERROR_NOT_SEARCH:
		cout << "주소정보를 찾을 수 없습니다." << endl;
		break;
	case ERROR_LOAD_FAIL:
		cout << "addressbook.book 파일을 불러올수 없습니다." << endl;
		break;
	default:
		break;
	}
}

template <class Type>
int AddressBook<Type>::isEmpty() {
	int isEmpty = TRUE;

	if ( this->list->getLength() > 0) {
		isEmpty = FALSE;
	}

	return isEmpty;
}

template <class Type>
void AddressBook<Type>::input() {
	Type info;
	char yesno;
	string name;
	string phone;
	string address;

	cout << "이름 : ";
	cin >> name;
	info.setName(name);

	cout << "전화번호 : ";
	cin >> phone;
	info.setPhone(phone);

	cout << "주소 : ";
	cin >> address;
	info.setAddress(address);

	cout << "입력된 정보" << endl;
	this->printHeader(FALSE);
	this->printPersonInfo(info, FALSE);

	cin.sync();
	cout << "추가하시겠습니까 ? (y/n) :";
	cin.get(yesno);
	
	if (yesno == 'y') {
		this->list->append(info);
		cout << "추가되었습니다." << endl;
	}
}

template <class Type>
void AddressBook<Type>::remove() {
	string name;
	int removeIndex = -1;
	char yesno;

	if (this->isEmpty() == TRUE) {
		this->print_error(ERROR_EMPTY);
		return;
	}

	cout << "삭제할 이름: ";
	cin >> name;

	removeIndex = this->list->findName(name);

	if (removeIndex == -1) {
		this->print_error(ERROR_NOT_SEARCH);
		return;
	}

	this->printHeader(FALSE);
	this->printPersonInfo(this->list->viewAt(removeIndex), FALSE);

	cin.sync();
	cout << "삭제하겠습니까? (y/n) :";
	cin.get(yesno);


	if (yesno == 'y') {
		this->list->erase(removeIndex);
		cout << "삭제되었습니다." << endl;
	}
}

template <class Type>
void AddressBook<Type>::modify() {
	//string name;
	int modifyIndex = -1;
	char yesno;
	Type info;
	Node<Type> *target;

	string name;
	string phone;
	string address;

	if (this->isEmpty() == TRUE) {
		this->print_error(ERROR_EMPTY);
		return;
	}

	cout << "수정할 이름: ";
	cin >> name;

	modifyIndex = this->list->findName(name);

	if (modifyIndex == -1) {
		this->print_error(ERROR_NOT_SEARCH);
		return;
	}

	this->printHeader(FALSE);
	this->printPersonInfo(this->list->viewAt(modifyIndex), FALSE);

	cin.sync();
	cout << "수정하겠습니까? (y/n) :";
	cin.get(yesno);

	if (yesno == 'y') {
		cout << "이름 : ";
		cin >> name;
		info.setName(name);

		cout << "전화번호 : ";
		cin >> phone;		
		info.setPhone(phone);

		cout << "주소 : ";
		cin >> address;
		info.setAddress(address);

		cout << "수정된 정보\n";
		this->printHeader(FALSE);
		this->printPersonInfo(info, FALSE);

		target = this->list->getNode(modifyIndex);

		target->info->setName(info.getName());
		target->info->setPhone(info.getPhone());
		target->info->setAddress(info.getAddress());

		cout << "수정되었습니다." << endl;
	}
}

template <class Type>
void AddressBook<Type>::search() {
	string name;
	int foundIndex = -1;

	if (this->isEmpty() == TRUE) {
		this->print_error(ERROR_EMPTY);
		return;
	}

	cout << "검색할 이름: ";
	cin >> name;

	foundIndex = this->list->findName(name);

	if (foundIndex == -1) {
		this->print_error(ERROR_NOT_SEARCH);
		return;
	}

	this->printHeader(FALSE);
	this->printPersonInfo(this->list->viewAt(foundIndex), FALSE);
}

template <class Type>
void AddressBook<Type>::printHeader(int printNum) {
	cout << "----------------------------------------------" << endl;
	if (printNum == TRUE) {
		cout << "번호  이름      전화번호      주소" << endl;
	}
	else {
		cout << "이름      전화번호      주소" << endl;
	}
	cout << "----------------------------------------------" << endl;
}

template <class Type>
void AddressBook<Type>::printPersonInfo(Type &info, int printNum) {
	if (printNum != FALSE) {
		//cout.width(4);
		cout << setw(4) << left << printNum;
		cout << "  ";
	}
	cout << info;
	cout << endl;
}

template <class Type>
void AddressBook<Type>::printPersonInfoPointer(Type *info, int printNum) {
	if (printNum != FALSE) {
		//cout.width(4);
		cout << setw(4) << left << printNum;
		cout << "  ";
	}
	cout << (*info);
	//cout << endl;
}

template <class Type>
void AddressBook<Type>::printAll() {
	int number = 1;
	Node<Type> *target;

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

template <class Type>
void AddressBook<Type>::save() {
	ofstream file;
	Node<Type> *target;

	if (this->isEmpty() == TRUE) {
		this->print_error(ERROR_EMPTY);
		return;
	}

	file.open("addressbook.dat", ios::out);

	target = this->list->moveFirst();

	if (file.is_open()) {
		while (this->list->isTail() != TRUE) {
			file << target->info->getName() << endl;			
			file << target->info->getPhone() << endl;
			file << target->info->getAddress() << endl;
			target = this->list->moveNext();
		}
		file.close();
	}

	//아래 코드가 필요한지 확인이 필요하다.
	target = nullptr;

	cout << "addressbook.dat 파일에 저장하였습니다." << endl;
}

template <class Type>
void AddressBook<Type>::load() {
	ifstream file;
	Type info;

	string name;
	string phone;
	string address;

	this->list->eraseAll();
	
	file.open("addressbook.dat", ios::in);

	if (!file.is_open()) {
		this->print_error(ERROR_LOAD_FAIL);
		return;
	}

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, name);
			info.setName(name);

			getline(file, phone);
			info.setPhone(phone);

			getline(file, address);
			info.setAddress(address);

			if (info.getName() == "") {
				file.close();
				break;
			}
			this->list->append(info);
		}
		file.close();
	}

	cout << "addressbook.dat 파일을 불러왔습니다." << endl;
}

template <class Type>
void AddressBook<Type>::testSetup() {
	int index = 0;

	/*
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
	*/
	Type sample[10];

	sample[0].setName("aaa");
	sample[0].setPhone("0001112222");
	sample[0].setAddress("acb");

	sample[1].setName("bbb");
	sample[1].setPhone("0001113333");
	sample[1].setAddress("abc");

	sample[2].setName("ccc");
	sample[2].setPhone("0001114444");
	sample[2].setAddress("abc");
	
	sample[3].setName("ddd");
	sample[3].setPhone("0001115555");
	sample[3].setAddress("abc");

	sample[4].setName("eee");
	sample[4].setPhone("0001116666");
	sample[4].setAddress("abc");

	sample[5].setName("fff");
	sample[5].setPhone("0001117777");
	sample[5].setAddress("abc");
	
	sample[6].setName("ggg");
	sample[6].setPhone("0001118888");
	sample[6].setAddress("abc");
	
	sample[7].setName("hhh");
	sample[7].setPhone("0001119999");
	sample[7].setAddress("abc");

	sample[8].setName("iii");
	sample[8].setPhone("0001110000");
	sample[8].setAddress("abc");

	sample[9].setName("jjj");
	sample[9].setPhone("0002220000");
	sample[9].setAddress("abc");
	
	for (index = 0; index < 10; index++) {
		this->list->append(sample[index]);
	}
}