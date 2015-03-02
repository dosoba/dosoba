# -*- coding: utf-8 -*-

"""
Name : main.cpp
Date : 2015.01.23
Writer : Sejoong Kim
"""

class personalInfo:
    #constructor
    def __init__(self, info = None):
        self._name = info._name if info else ""
        self._phone = info._phone if info else ""
        self._address = info._address if info else ""

    #Destructor
    def __del__(self):
        self._name = ""
        self._phone = ""
        self._address = ""

    #Built-in Functions
    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value

    @property
    def phone(self):
        return self._phone

    @phone.setter
    def phone(self, value):
        self._phone = value

    @property
    def address(self):
        return self._address

    @address.setter
    def address(self, value):
        self._address = value

    #comparison
    def __eq__(self, other):
        isEqual = False

        if type(other) is personalInfo:
            if (self.name == other.name):
                isEqual = True
        elif type(other) is str:
            if (self.name == other):
                isEqual = True
        else:
            isEqual = False
        return isEqual