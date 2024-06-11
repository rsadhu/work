import socket

def start_server(port):
    # Create a socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to a public host and port
    server_socket.bind(('0.0.0.0', port))

    # Become a server socket
    server_socket.listen(5)

    print(f"Listening on port {port}...")

    while True:
        # Establish connection with client
        client_socket, addr = server_socket.accept()
        print(f"Got connection from {addr}")

        # Receive data from the client
        data = client_socket.recv(1024)
        print(f"Received: {data.decode()}")

        # Close the connection with the client
        client_socket.close()

# Start the server on port 12345
start_server(5555)
