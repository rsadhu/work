#
#   Hello World server in Python
#   Binds REP socket to tcp://*:5555
#   Expects b"Hello" from client, replies with b"World"
#

import time
import zmq

context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:5556")

file_path = '/home/rsadhu/Downloads/ubuntu-24.04-desktop-amd64.iso'
size = 100  # Number of bytes to read
with open(file_path, 'rb') as file:
    while True:
        print(socket.recv())
        #data = file.read(size)    
        
        # if data == None or data == "":
        #     socket.send("stop")    
        #     break

        #  Do some 'work'
        time.sleep(1)

        #  Send reply back to client
        socket.send(b"rakesh")
