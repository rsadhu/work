

def cppMethodArgumentType(self,val):
    if val:
        return "const "+self+" &"
    else:
        return self



if __name__ == "__main__":
    res = cppMethodArgumentType("char",1)
    print(res)
    res = cppMethodArgumentType("char",0)
    print(res)
    
    

