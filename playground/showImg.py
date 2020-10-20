import cv2

class A:
    def __init__(self):
        self.a =  10
        self._b = 11
        self.__c = 12;

    def display(self):
        print(self.a, self._b, self.__c)


def showPic(file):
    try:
        img = cv2.imread(file)
        cv2.imshow('image', img)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
    except:
        print(""" Error occured """)



a = A()
a.display()


##showPic("/home/rsadhu/test1.gif")
