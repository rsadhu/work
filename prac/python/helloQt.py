import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import (QPushButton, QHBoxLayout)

"""

class MyWidget(QtWidgets.QWidget()):
   def __init__(self,parent):
        super(MyWidget,self).__init__(parent,self)
        setGeometry(100,100,500,400)
        window.setWindowTitle("PyQT Tuts!")
        
   def mousePressEvent(self,event):
       print ("mouse pressed")
       """
global window 
def slotBtnClicked():
    print ("button pressed")
    window.setStyleSheet("background:red")
    
if __name__ == '__main__':
    app = QtWidgets.QApplication.instance()
    if app is None:
        app = QtWidgets.QApplication(sys.argv)
    else:
        print('QApplication instance already exists: %s' % str(app))

    window = QtWidgets.QWidget()
    window.setGeometry(100, 100, 500, 300)
    window.setWindowTitle("PyQT Tuts!")
    layout = QHBoxLayout (window)
    btn = QPushButton(window)
    layout.addWidget(btn)
    btn.setText("pressme")
   # btn.connect(btn,SIGNAL(clicked()),[window](){});
    btn.clicked.connect(slotBtnClicked)
    window.show()    
    app.exec_()