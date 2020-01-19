import sys
#from PyQt4.QtGui import *

import glob, re


class Base:
    def __init__(self):
        print ("base::constructor")
    def __del__(self):
        print("base::destructor")
    def display(self):
        print("display")
        
class Der(Base):
    def __init__(self):
        print ("der::constructor")
    def __del__(self):
        print("der::destructor")
    def foo(self):
        print("Der::foo")
        
def isEmail(src):
    print (""+src)
    print(re.findall(r'[\w\.-]+@[\w\.-]+(\.[\w]+)+',src))
    

if __name__== "__main__":
    print ("main")
    #t = Base()
    #t.display();
    #del t
    d = Der()
    d.display()
    d.foo()
    del d
    isEmail("rakeshsadhu@gmail.com")
