import PyQt5;
def factorial(n):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)

class Test:
    name=""
    age=0
    address=""
    def __init__(self):
        self.name="test"
        self.age=100
        self.address="usa california"
    def __init__(self,name,age,address):
        self.name=name
        self.age=age
        self.address=address
    def displayAll(self):
        print (self.name,self.age,self.address)
        
        
test = Test("rakesh","35","ankara turkey")
print(test.displayAll())

try:
    filehandler = open("test.txt","a")
    write("this is a test program, rakesh here..")
    filehandler.close()
except:
    print("file couldnt be open for writing")