#
#   Hello World client in Python
#   Connects REQ socket to tcp://localhost:5555
#   Sends "Hello" to server, expects "World" back
#

import zmq

context = zmq.Context()

#  Socket to talk to server
print("Connecting to hello world server…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://192.168.178.36.:5556")

file_path = 'ubuntu-24.04-desktop-amd64.iso'
size = 1024

socket.send(b"hello")
with open(file_path, 'ab') as file:

    while True:
        #  Wait for next request from client
        message = socket.recv()
        if message == "stop":
            break

        # Write the specified number of bytes to the file
        file.write(b'\x00' * size)  # Writing zeros as an example
