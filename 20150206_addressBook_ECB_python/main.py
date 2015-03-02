# -*- coding: utf-8 -*-

"""
Name : main.cpp
Date : 2015.03.02
Writer : Sejoong Kim
"""

import addressBookCtrl

def main():
    book = addressBookCtrl.addressbook()

    book.testSetup()
    book.launch()

if __name__ == "__main__":
    main()