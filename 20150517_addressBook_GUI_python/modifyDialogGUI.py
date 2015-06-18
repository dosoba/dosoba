# -*- coding: utf-8 -*-

import wx

class ModifyDialog(wx.Dialog):

    title = 'Modify Function'
    size=(300, 220)

    def __init__(self, parent):
        super(ModifyDialog, self).__init__(parent,
                                        title = self.title,
                                        size=self.size)
        self.init_ui()

    def init_ui(self):
        panel = wx.Panel(self)
        vbox = wx.BoxSizer(wx.VERTICAL)

        #Input Fields
        hbox = wx.BoxSizer(wx.HORIZONTAL)
        fgs = wx.FlexGridSizer(3, 2, 10, 25)

        name = wx.StaticText(panel, label = "name    : ")
        phoneNumber = wx.StaticText(panel, label = "phone   : ")
        address = wx.StaticText(panel, label = "address : ")

        tc1 = wx.TextCtrl(panel)
        tc2 = wx.TextCtrl(panel)
        tc3 = wx.TextCtrl(panel, style=wx.TE_MULTILINE)

        fgs.AddMany([
            (name), (tc1, 1, wx.EXPAND),
            (phoneNumber), (tc2, 1, wx.EXPAND),
            (address, 1, wx.EXPAND), (tc3, 1, wx.EXPAND)
        ])
        fgs.AddGrowableRow(2, 1)
        fgs.AddGrowableCol(1, 1)
        hbox.Add(fgs, proportion = 1, flag = wx.ALL | wx.EXPAND, border = 10)
        vbox.Add(hbox, flag = wx.ALIGN_CENTER)

        #line
        line = wx.StaticLine(panel)
        vbox.Add(line, flag=wx.EXPAND|wx.BOTTOM, border=10)

        #button fields
        buttonBox = wx.BoxSizer(wx.HORIZONTAL)
        btn1 = wx.Button(panel, label = 'Modify', size = (100, 30))
        buttonBox.Add(btn1)

        btn2 = wx.Button(panel, label = 'Cancel', size = (100, 30))
        buttonBox.Add(btn2, flag = wx.LEFT, border = 20)

        vbox.Add(buttonBox, flag = wx.ALIGN_CENTER)
        panel.SetSizer(vbox)

    def OnClose(self, e):
        self.Destroy()

    def DisplayDialog(self, flagOfShow):
        self.Show(flagOfShow)