# -*- coding: utf-8 -*-

import wx

class SearchDialog(wx.Dialog):

    title = 'Search Function'
    size=(300,140)

    def __init__(self, parent):
        super(SearchDialog, self).__init__(parent,
                                           title = self.title,
                                           size = self.size)
        self.init_ui();

    def init_ui(self):
        panel = wx.Panel(self)
        vbox = wx.BoxSizer(wx.VERTICAL)

        hbox = wx.BoxSizer(wx.HORIZONTAL)
        fgs = wx.FlexGridSizer(1, 2, 10, 25)
        name = wx.StaticText(panel, label = "name    : ")
        tc1 = wx.TextCtrl(panel)
        fgs.AddMany([
            (name), (tc1, 1, wx.EXPAND)
        ])
        hbox.Add(fgs, proportion = 1, flag = wx.ALL | wx.EXPAND, border = 10)
        vbox.Add(hbox, flag = wx.ALIGN_CENTER)

        #line
        line = wx.StaticLine(panel)
        vbox.Add(line, flag=wx.EXPAND|wx.BOTTOM, border=10)

        #button fields
        buttonBox = wx.BoxSizer(wx.HORIZONTAL)
        btn1 = wx.Button(panel, label = 'Search', size = (100, 30))
        buttonBox.Add(btn1)

        btn2 = wx.Button(panel, label = 'Cancel', size = (100, 30))
        buttonBox.Add(btn2, flag = wx.LEFT, border = 20)

        vbox.Add(buttonBox, flag = wx.ALIGN_CENTER)
        panel.SetSizer(vbox)

    def OnClose(self, e):
        self.Destroy()

    def DisplayDialog(self, flagOfShow):
        self.Show(flagOfShow)