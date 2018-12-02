class Test:
    def init(self):
        print("Constructor")
        _hash[1] = "one"
        _hash[0] = "zero"
        _hash[2] = "two"
        
    def display(self):
        print (" Test::display ")
        
    def getValue(self,val):
        return _hash[val]
    
    _hash = {}
if __name__ == '__main__':
    t = Test()
    t.display();
    print(t.getValue(0))

