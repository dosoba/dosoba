# -*- coding: utf-8 -*-

"""
Name : main.cpp
Date : 2015.03.02
Writer : Sejoong Kim
"""

import personInfo
import linkedList
import MySQLdb as mdb
import addressBookUI

class addressbook(object):
    def __init__(self):
        self.list = linkedList.linkedlist()

    def __del__(self):
        self.list.deleteAll()
        del self.list

    def isEmpty(self):
        isEmpty = True

        if (self.list.getLength() > 0):
            isEmpty = False

        return isEmpty

    def input(self, info):
        self.list.append(info)

    def remove(self, removeIndex):
        self.list.deleteNode(removeIndex)

    def modify(self, modifyIndex, info):
        target = self.list.getNode(modifyIndex)
        target.data = info

    def search(self, name):
        foundIndex = self.list.find(name)
        return foundIndex

    def save(self):
        if (self.isEmpty() == True):
            self.print_error(self.ERROR_EMPTY)
            return None

        target = self.list.moveFirst()

        with open('addressbook.dat', 'w') as f:
            while (self.list.isTail() != True):
                f.write(target.data.name + '\n')
                f.write(target.data.phone + '\n')
                f.write(target.data.addres + '\n')
                target = self.list.moveNext()

        print "addressbook.dat 파일에 저장하였습니다."

    def load(self):
        self.list.deleteAll()

        f = open('addressbook.dat', 'r')
        f.seek(0,2)
        eof = f.tell()
        f.seek(0)
        while True:
            info = personInfo.personalInfo()
            info.name = f.readline().rstrip('\n')
            info.phone = f.readline().rstrip('\n')
            info.address = f.readline().rstrip('\n')
            self.list.append(info)
            if eof == f.tell(): break

        print "addressbook.dat 파일을 불러왔습니다."

    def save_db(self):
        if (self.isEmpty() == True):
            self.print_error(self.ERROR_EMPTY)
            return None
        target = self.list.moveFirst()
        con = mdb.connect('localhost', 'root', 'qwop1290', 'studydb')
        with con:
            cur = con.cursor()
            cur.execute("DROP TABLE IF EXISTS addressbook")
            cur.execute("CREATE TABLE addressbook(id INT PRIMARY KEY AUTO_INCREMENT, "
                        "name VARCHAR(10) UNIQUE NOT NULL, "
                        "phone VARCHAR(13) DEFAULT NULL, "
                        "address VARCHAR(50) DEFAULT NULL)")

            while (self.list.isTail() != True):
                cur.execute("INSERT INTO addressbook (name, phone, address) "
                "VALUES (\'%s\', \'%s\', \'%s\')" % (target.data.name, target.data.phone, target.data.address))
                target = self.list.moveNext()

        print "studydb database내 addressbook table에 저장하였습니다."

    def load_db(self):
        self.list.deleteAll()

        con = mdb.connect('localhost', 'root', 'qwop1290', 'studydb')
        with con:
            cur = con.cursor(mdb.cursors.DictCursor)
            cur.execute("SELECT * FROM addressbook")
            rows = cur.fetchall()

            for row in rows:
                info = personInfo.personalInfo()
                info.name = row['name']
                info.phone = row['phone']
                info.address = row['address']
                self.list.append(info)

        print "studydb database내 addressbook table을 불러왔습니다."

    def testSetup(self):
        samples = []

        info = personInfo.personalInfo()
        info.name = "aaa"
        info.phone = "0001112222"
        info.address = "acb"
        samples.append(info)

        info = personInfo.personalInfo()
        info.name = "bbb"
        info.phone = "000111333"
        info.address = "acb"
        samples.append(info)

        info = personInfo.personalInfo()
        info.name = "ccc"
        info.phone = "000111444"
        info.address = "acb"
        samples.append(info)

        info = personInfo.personalInfo()
        info.name = "ddd"
        info.phone = "0001115555"
        info.address = "acb"
        samples.append(info)

        info = personInfo.personalInfo()
        info.name = "eee"
        info.phone = "0001116666"
        info.address = "acb"
        samples.append(info)

        info = personInfo.personalInfo()
        info.name = "fff"
        info.phone = "0001117777"
        info.address = "acb"
        samples.append(info)

        info = personInfo.personalInfo()
        info.name = "ggg"
        info.phone = "0001118888"
        info.address = "acb"
        samples.append(info)

        info = personInfo.personalInfo()
        info.name = "hhh"
        info.phone = "0001119999"
        info.address = "acb"
        samples.append(info)

        info = personInfo.personalInfo()
        info.name = "iii"
        info.phone = "0002220000"
        info.address = "acb"
        samples.append(info)

        info = personInfo.personalInfo()
        info.name = "jjj"
        info.phone = "0002221111"
        info.address = "acb"
        samples.append(info)

        for index in range(10):
            self.list.append(samples[index])

    def launch(self):
        ui = addressBookUI.addressbook()
        menu = -1

        while (menu != 0):
            ui.printMainMenu()

            menu = raw_input("menu: ")

            menu = int(menu)

            if menu == ui.MENU_INPUT:
                ui.input(self)
            elif menu == ui.MENU_REMOVE:
                ui.remove(self)
            elif menu == ui.MENU_MODIFY:
                ui.modify(self)
            elif menu == ui.MENU_SEARCH:
                ui.search(self)
            elif menu == ui.MENU_ALL_PRINT:
                ui.printAll(self)
            elif menu == ui.MENU_SAVE:
                self.save_db()
            elif menu == ui.MENU_LOAD:
                self.load_db()
            elif menu == ui.MENU_FINISH:
                ui.print_finish()
            else:
                ui.print_error(ui.ERROR_NO_MENU)

            if (menu != ui.MENU_FINISH):
                raw_input("menu 화면으로 돌아갑니다. (아무키나 누르세요)")