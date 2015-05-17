# -*- coding: utf-8 -*-

"""
Name : addressBookUI.py
Date : 2015.03.02
Writer : Sejoong Kim
"""

import personInfo


class addressbook(object):
    def __init__(self):
        self.MENU_INPUT = 1
        self.MENU_REMOVE = 2
        self.MENU_MODIFY = 3
        self.MENU_SEARCH = 4
        self.MENU_ALL_PRINT = 5
        self.MENU_SAVE = 6
        self.MENU_LOAD = 7
        self.MENU_FINISH = 0
        self.ERROR_NO_MENU = 1
        self.ERROR_FULL = 2
        self.ERROR_EMPTY = 3
        self.ERROR_NOT_SEARCH = 4
        self.ERROR_LOAD_FAIL = 5

    def printMainMenu(self):
        print """\
1. 주소정보를 입력한다.
2. 주소정보를 삭제한다.
3. 주소정보를 수정한다.
4. 주소정보를 검색한다.
5. 전체 주소록을 출력한다.
6. 주소록 파일에 저장한다.
7. 주소록 파일을 불러온다.
0. 종료한다."""

    def print_finish(self):
        print "프로그램을 종료합니다."

    def print_error(self, error):
        if error == self.ERROR_NO_MENU:
            print "없는 번호를 입력하였습니다."
        elif error == self.ERROR_FULL:
            print "주소록이 가득 찼습니다."
        elif error == self.ERROR_EMPTY:
            print "주소록이 비어있습니다."
        elif error == self.ERROR_NOT_SEARCH:
            print "주소정보를 찾을 수 없습니다."
        elif error == self.ERROR_LOAD_FAIL:
            print "addressbook.dat 파일을 불러올수 없습니다."
        else:
            pass

    def printHeader(self, printNum):
        print "----------------------------------------------"
        if (printNum != -1):
            print "번호  이름     전화번호      주소"
        else:
            print "이름     전화번호      주소"
        print "----------------------------------------------"

    def printPersonInfo(self, info, printNum):
        if (printNum != -1):
            print "%-4s" % printNum,
        print "%-7s %-14s %-50s" % (info.name, info.phone, info.address)

    def input(self, book):
        info = personInfo.personalInfo()

        info.name = raw_input("이름 : ")
        info.phone = raw_input("전화번호 : ")
        info.address = raw_input("주소 : ")

        print "입력된 정보"
        self.printHeader(-1)
        self.printPersonInfo(info, -1)

        yesno = raw_input("추가하시겠습니까? (y/n) : ")
        if (yesno == 'y' or 'Y'):
            book.input(info)
            print "추가되었습니다."

    def remove(self, book):
        if (book.isEmpty() == True):
            self.print_error(self.ERROR_EMPTY)
            return None

        name = raw_input("삭제할 이름 : ")
        removeIndex = book.list.find(name)

        if(removeIndex == -1):
            self.print_error(self.ERROR_NOT_SEARCH)
            return None

        self.printHeader(-1)
        self.printPersonInfo(book.list.viewAt(removeIndex), -1)

        yesno = raw_input("삭제하시겠습니까? (y/n) : ")
        if (yesno == 'y' or 'Y'):
            book.remove(removeIndex)
            print "삭제되었습니다."

    def modify(self, book):
        if (book.isEmpty() == True):
            self.print_error(self.ERROR_EMPTY)
            return None

        name = raw_input("수정할 이름: ")
        modifyIndex = book.list.find(name)

        if (modifyIndex == -1):
            self.print_error(self.ERROR_NOT_SEARCH)
            return None

        self.printHeader(-1)
        self.printPersonInfo(book.list.viewAt(modifyIndex), -1)

        yesno = raw_input("수정하시겠습니까? (y/n) : ")
        info = personInfo.personalInfo()
        if (yesno == 'y' or 'Y'):
            info.name = raw_input("이름 : ")
            info.phone = raw_input("전화번호 : ")
            info.address = raw_input("주소 : ")

            print "수정된 정보"
            book.modify(modifyIndex, info)
            self.printHeader(-1)
            self.printPersonInfo(book.list.viewAt(modifyIndex), -1)
            print "수정되었습니다."

    def search(self, book):
        if (book.isEmpty() == True):
            self.print_error(self.ERROR_EMPTY)
            return None

        name = raw_input("검색할 이름 : ")
        foundIndex = book.search(name)

        if (foundIndex == -1):
            self.print_error(self.ERROR_NOT_SEARCH)
            return None

        self.printHeader(-1)
        self.printPersonInfo(book.list.viewAt(foundIndex), -1)

    def printAll(self, book):
        number = 1
        if (book.isEmpty() == True):
            self.print_error(self.ERROR_EMPTY)
            return None

        self.printHeader(1)
        target = book.list.moveFirst()
        while (book.list.isTail() != True):
            self.printPersonInfo(target.data, number)
            target = book.list.moveNext()
            number = number + 1