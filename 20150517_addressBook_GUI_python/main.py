# -*- coding: utf-8 -*-

"""
Name : main.cpp
Date : 2015.03.02
Writer : Sejoong Kim
"""

#import addressBookCtrl
import wx
import addressBookGUI

def main():
    '''
    Title : CUI

    book = addressBookCtrl.addressbook()
    book.testSetup()
    book.launch()
    '''

    '''
    title : implement main function of GUI
    date : '15.06.10
    '''
    main_app = wx.App()
    main_ui = addressBookGUI.MainFrame(None)
    main_ui.Show(True)
    main_app.MainLoop()

if __name__ == "__main__":
    main()