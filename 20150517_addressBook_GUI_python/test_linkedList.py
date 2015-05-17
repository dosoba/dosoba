# -*- coding: utf-8 -*-

"""
Name : test_linkedList.py
Date : 2015.03.05
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

    def test_insert(self):
        self.testInfo4 = personalInfo("test4", "0104444444", "dddd")
        self.list.insert(1, self.testInfo4)

        self.assertEqual(self.list.getLength(), 4)

        self.assertEqual(self.list.viewAt(1).name, "test4")
        self.assertEqual(self.list.viewAt(1).phone, "0104444444")
        self.assertEqual(self.list.viewAt(1).address, "dddd")

    def test_deleteNode(self):
        self.list.deleteNode(0)

        self.assertEqual(self.list.getLength(), 2)

        self.assertEqual(self.list.viewAt(0).name, "test2")
        self.assertEqual(self.list.viewAt(0).phone, "0102222222")
        self.assertEqual(self.list.viewAt(0).address, "bbbb")

    def test_deleteAll(self):
        self.list.deleteAll()

        self.assertEqual(self.list.getLength(), 0)

    def test_moveFirst(self):
        self.list.moveFirst()

        self.assertEqual(self.list.viewAt(0).name, "test1")
        self.assertEqual(self.list.viewAt(0).phone, "0101111111")
        self.assertEqual(self.list.viewAt(0).address, "aaaa")

    def test_moveNext(self):
        self.list.moveFirst()
        self.list.moveNext()

        self.assertEqual(self.list.viewAt(1).name, "test2")
        self.assertEqual(self.list.viewAt(1).phone, "0102222222")
        self.assertEqual(self.list.viewAt(1).address, "bbbb")

    def test_moveLast(self):
        self.list.moveFirst()
        self.list.moveLast()

        self.assertEqual(self.list.viewAt(2).name, "test3")
        self.assertEqual(self.list.viewAt(2).phone, "0103333333")
        self.assertEqual(self.list.viewAt(2).address, "cccc")

    def test_isTail(self):
        self.list.moveLast()
        self.assertEqual(self.list.isTail(), False)
        self.list.moveNext()
        self.assertEqual(self.list.isTail(), True)

    def test_getNode(self):
        self.assertEqual(self.list.getNode(1).data.name, "test2")
        self.assertEqual(self.list.getNode(1).data.phone, "0102222222")
        self.assertEqual(self.list.getNode(1).data.address, "bbbb")

    def test_viewAt(self):
        self.assertEqual(self.list.viewAt(2).name, "test3")
        self.assertEqual(self.list.viewAt(2).phone, "0103333333")
        self.assertEqual(self.list.viewAt(2).address, "cccc")

    def test_findName(self):
        self.assertEqual(self.list.find("test1"), 0)

if __name__ == '__main__':
    unittest.main()

















