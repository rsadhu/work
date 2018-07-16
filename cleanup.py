import os
#def cleanup():
#cur_dir =  os.getcwd()
#file_name ="arrays.c"
#while True:
#file_list = os.listdir(cur_dir)
#parent_dir = os.path.dirname(cur_dir)
#if file_name in file_list:
#print "exists in ", cur_dir, "  ",file_name
#break
#else	/* : */
#if cur_dir == parent_dir:
#print "File not found"
#else:
#cur_dir = parent_dir
  
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


print find('*.*~' ,'/home/rsadhu/')
