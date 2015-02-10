# -*- coding: utf-8 -*-

"""
Name : main.cpp
Date : 2015.01.23
Writer : Sejoong Kim
"""

import addressBookCtrl
import addressBookUI

def main():
    menu = -1
    book = addressBookCtrl.addressbook()

    book.testSetup()

    while (menu != 0):
        addressBookUI.printMainMenu()

        menu = raw_input("menu: ")

        menu = int(menu)

        if menu == addressBookUI.MENU_INPUT:
            addressBookUI.input(book)
        elif menu == addressBookUI.MENU_REMOVE:
            addressBookUI.remove(book)
        elif menu == addressBookUI.MENU_MODIFY:
            addressBookUI.modify(book)
        elif menu == addressBookUI.MENU_SEARCH:
            addressBookUI.search(book)
        elif menu == addressBookUI.MENU_ALL_PRINT:
            addressBookUI.printAll(book)
        elif menu == addressBookUI.MENU_SAVE:
            book.save_db()
        elif menu == addressBookUI.MENU_LOAD:
            book.load_db()
        elif menu == addressBookUI.MENU_FINISH:
            addressBookUI.print_finish()
        else:
            addressBookUI.print_error(addressBookUI.ERROR_NO_MENU)

        if (menu != addressBookUI.MENU_FINISH):
            raw_input("menu 화면으로 돌아갑니다. (아무키나 누르세요)")

if __name__ == "__main__":
    main()