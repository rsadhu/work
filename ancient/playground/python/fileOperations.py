clMap = {}
ldMap = {}

def readSrcFile(fileName):
    f = open(fileName)
    lines = f.readlines()
    for line in lines:
        if line.find("CL") != -1:
            values = line.split(":")
            if len(values) == 2:
                clMap[values[0]] = values[1]
        elif line.find("LD") != -1:
            values = line.split(":")
            if len(values) == 2:
                ldMap[values[0]] = values[1]
        

    
def readFile(filename):
    f = open(filename)
    lines = f.readlines();
    start = False
    ended = False
    for line in lines:
        if line.find("//{") != -1:
            start = True
        
        if line.find("//}") != -1:      
            ended = True
            
            
        if start == True and ended == False:
            values = line.split(":")
            if len(values) == 2:
                firstEntries = values[0].split(" ")
            #    print(firstEntries[6])
            #    print (values[1])
    
if __name__ == "__main__":
    print ("<<===1==>>")
    
    readSrcFile("/home/rsadhu/dev/design-master/hu-ui2020_designmaster/sg/global/StyleColors.qml")
     
    print ("<<===2==>>")
     
    readFile("/home/rsadhu/dev/widget_gallery-shh/uisdk/widget-library/src/plugin/qml/components/BaseTheme.qml")
     
    print (clMap)
    