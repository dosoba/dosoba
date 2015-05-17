# -*- coding: utf-8 -*-

import wx
class MainWindow(wx.Frame):
    def __init__(self, parent, title, size):
        super(MainWindow, self).__init__(parent, title = title, size = size)
        self.InitUI()
        self.Centre()
        self.Show(True)

    def InitUI(self):
        self.InitMenu()
        self.InitView()

    def InitMenu(self):
        menubar = wx.MenuBar()

        fileMenu = wx.Menu()
        saveMenu = fileMenu.Append(wx.ID_SAVE, '&Save\tCtrl+S')
        loadMenu = fileMenu.Append(wx.ID_ANY, 'L&oad\tCtrl+O')
        saveDBMenu = fileMenu.Append(wx.ID_ANY, 'S&aveDB\tCtrl+A')
        loadDBMenu = fileMenu.Append(wx.ID_ANY, '&LoadDB\tCtrl+L')
        exitMenu = fileMenu.Append(wx.ID_EXIT, 'E&xit\tCtrl+X')

        helpMenu = wx.Menu()
        aboutMenu = helpMenu.Append(wx.ID_ABOUT, 'A&bout\tCtrl+B')

        menubar.Append(fileMenu, '&File')
        menubar.Append(helpMenu, '&Help')
        self.SetMenuBar(menubar)


    def InitView(self):

        panel = wx.Panel(self, -1)

        # basic box
        hbox = wx.BoxSizer(wx.HORIZONTAL)

        # List Box
        self.listbox = wx.ListBox(panel, -1)
        hbox.Add(self.listbox, 1, wx.EXPAND | wx.ALL, 20)

        # Button box
        buttonPanel = wx.Panel(panel, -1)
        vbox = wx.BoxSizer(wx.VERTICAL)
        addButton = wx.Button(buttonPanel, label = 'ADD', size = (80, 30))
        vbox.Add(addButton, 0, wx.TOP, 20)

        deleteButton = wx.Button(buttonPanel, label = 'DELETE', size = (80, 30))
        vbox.Add(deleteButton, 0, wx.TOP, 60)

        searchButton = wx.Button(buttonPanel, label = 'SEARCH', size = (80, 30))
        vbox.Add(searchButton, 0, wx.TOP, 60)

        modifyButton = wx.Button(buttonPanel, label = 'MODIFY', size = (80, 30))
        vbox.Add(modifyButton, 0, wx.TOP, 60)

        buttonPanel.SetSizer(vbox)
        hbox.Add(buttonPanel, 0.6, wx.EXPAND | wx.RIGHT, 20)

        panel.SetSizer(hbox)


class AddWindow(wx.Frame):
    def __init__(self, parent, title, size):
        super(AddWindow, self).__init__(parent,
                                        title = title,
                                        size=size,
                                        style=wx.RESIZE_BORDER | wx.SYSTEM_MENU | wx.CAPTION | wx.CLOSE_BOX | wx.CLIP_CHILDREN)
        self.InitUI()
        self.Centre()
        self.Show()

    def InitUI(self):
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
        btn1 = wx.Button(panel, label = 'Add', size = (100, 30))
        buttonBox.Add(btn1)

        btn2 = wx.Button(panel, label = 'Cancel', size = (100, 30))
        buttonBox.Add(btn2, flag = wx.LEFT, border = 20)

        vbox.Add(buttonBox, flag = wx.ALIGN_CENTER)
        panel.SetSizer(vbox)

class SearchWindow(wx.Frame):
    def __init__(self, parent, title, size):
        super(SearchWindow, self).__init__(parent,
                                           title = title,
                                           size = size,
                                           style=wx.RESIZE_BORDER | wx.SYSTEM_MENU | wx.CAPTION | wx.CLOSE_BOX | wx.CLIP_CHILDREN)
        self.InitUI()
        self.Centre()
        self.Show()

    def InitUI(self):
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

class ModifyWindow(wx.Frame):
    def __init__(self, parent, title, size):
        super(ModifyWindow, self).__init__(parent,
                                        title = title,
                                        size=size,
                                        style=wx.RESIZE_BORDER | wx.SYSTEM_MENU | wx.CAPTION | wx.CLOSE_BOX | wx.CLIP_CHILDREN)
        self.InitUI()
        self.Centre()
        self.Show()

    def InitUI(self):
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




def main():
    mainWindow = wx.App()
    #MainWindow(None, title = 'AddressBook', size=(500, 400))
    #AddWindow(None, title = 'Add Function', size=(300, 220))
    #SearchWindow(None, title = 'Search Function', size=(300,140))
    ModifyWindow(None, title = 'Modify Function', size=(300, 220))
    mainWindow.MainLoop()


if __name__ == '__main__':
    main()