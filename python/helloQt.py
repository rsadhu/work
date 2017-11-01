import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import *
from PyQt5.QtGui import *


if __name__ == '__main__':
    app = QtWidgets.QApplication.instance()
    if app is None:
        app = QtWidgets.QApplication(sys.argv)
    else:
        print('QApplication instance already exists: %s' % str(app))

    window = QtWidgets.QWidget()
    window.setGeometry(100, 100, 500, 300)
    window.setWindowTitle("PyQT Tuts!")
    window.show()
    app.exec_()