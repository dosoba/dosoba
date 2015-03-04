# -*- coding: utf-8 -*-

"""
Name : test_linkedList.py
Date : 2015.03.04
Writer : Sejoong Kim
"""

from linkedList import linkedlist
from personInfo import personalInfo
import unittest

class TestLinkedList(unittest.TestCase):

    def setUp(self):
        self.testInfo1 = personalInfo("test1", "0101111111", "aaaa")
        self.testInfo2 = personalInfo("test2", "0102222222", "bbbb")
        self.testInfo3 = personalInfo("test3", "0103333333", "cccc")

        self.list = linkedlist()
        self.list.append(self.testInfo1)
        self.list.append(self.testInfo2)
        self.list.append(self.testInfo3)

    def tearDown(self):
        self.list.deleteAll()
        del self.list
        del self.testInfo1
        del self.testInfo2
        del self.testInfo3

    def test_get_length(self):
        self.assertEqual(self.list.getLength(), 3)

    def test_append(self):
        self.testInfo4 = personalInfo("test4", "0104444444", "dddd")
        self.list.append(self.testInfo4)

        self.assertEqual(self.list.getLength(), 4)
        #self.assertEqual(self.list.pos.data.name,"test4")
        #self.assertEqual(self.list.pos.data.phone, "0104444444")
        #self.assertEqual(self.list.pos.data.address, "dddd")

        self.assertEqual(self.list.viewAt(3).name, "test4")
        self.assertEqual(self.list.viewAt(3).phone, "0104444444")
        self.assertEqual(self.list.viewAt(3).address, "dddd")

if __name__ == '__main__':
    unittest.main()