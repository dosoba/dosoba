# -*- coding: utf-8 -*-

"""
Name : test_linkedList.py
Date : 2015.03.16
Writer : Sejoong Kim
"""

import unittest
import addressBookCtrl
import personInfo

class TestAddressBook(unittest.TestCase):
    def setUp(self):
        self.book = addressBookCtrl.addressbook()

        self.testInfo1 = personInfo.personalInfo("test1", "0001111111", "aaa")
        self.testInfo2 = personInfo.personalInfo("test2", "0002222222", "bbb")
        self.testInfo3 = personInfo.personalInfo("test3", "0003333333", "ccc")

        self.book.input(self.testInfo1)
        self.book.input(self.testInfo2)
        self.book.input(self.testInfo3)

    def tearDown(self):
        del self.book
        del self.testInfo1
        del self.testInfo2
        del self.testInfo3

    def test_input(self):
        testInfo = personInfo.personalInfo("test4", "0004444444", "ddd")
        self.book.input(testInfo)
        self.assertEqual(self.book.list.getNode(3).data.name, testInfo.name)
        self.assertEqual(self.book.list.getNode(3).data.phone, testInfo.phone)
        self.assertEqual(self.book.list.getNode(3).data.address, testInfo.address)

    def test_remove(self):
        self.book.remove(0)
        self.assertNotEqual(self.book.list.getNode(0).data.name, self.testInfo1.name)
        self.assertNotEqual(self.book.list.getNode(0).data.phone, self.testInfo1.phone)
        self.assertNotEqual(self.book.list.getNode(0).data.address, self.testInfo1.address)

    def test_modify(self):
        testInfo = personInfo.personalInfo("test4", "0004444444", "ddd")
        self.book.modify(0, testInfo)
        self.assertEqual(self.book.list.getNode(0).data.name, testInfo.name)
        self.assertEqual(self.book.list.getNode(0).data.phone, testInfo.phone)
        self.assertEqual(self.book.list.getNode(0).data.address, testInfo.address)

    def test_search(self):
        index = self.book.search("test2")

        self.assertEqual(self.book.list.getNode(index).data.name, "test2")
        self.assertEqual(self.book.list.getNode(index).data.phone, "0002222222")
        self.assertEqual(self.book.list.getNode(index).data.address, "bbb")
