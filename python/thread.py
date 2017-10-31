import thread

def mythread ( data ):
    print (data)
    

try:
    #thread.start_new_thread(mythread,"rakesh")
    thread.start_new_thread(mythread,"hello")
except BaseException as e:
    print("Exception "+str(e))
    
