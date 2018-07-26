import os
import os, fnmatch 

def find (pattern, path):
    result =[]
    for root, dirs, files in os.walk (path):
        print root  + " parent  "
     #   print dirs  + "  dirs  "
        for name in files:
            print name  +" file  "
            if fnmatch.fnmatch (name, pattern):
                result.append (os.path.join (root, name))
	return result 

def searchAndClean(whattoclean,wheretoclean):
    print "searchAndClean called";

searchAndClean("","");

#print find('*.*~' ,'/home/rsadhu/')
