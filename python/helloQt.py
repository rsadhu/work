import sys
import PyQt5
from PyQt5 import QtCore ,QtGui , QtWidgets
from PyQt5.QtCore import QDateTime, QThread


def myThread(arg):
    print (arg)


if __name__=="__main__":
    try:
        datetime = QDateTime()
        print (datetime.currentDateTime())
        thread  = QThread(myThread)
        #thread.
        thread.start()
    except BaseException as e:
        print (str(e))
        