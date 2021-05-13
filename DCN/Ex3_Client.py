import socket
def client_program():
    host = socket.gethostname() # as both code is running on same pc
    port = 5000 # socket server port number
    client_socket = socket.socket() # instantiate
    client_socket.connect((host, port)) # connect to the server
    print('server connected ')# + data) # show in terminal
    client_socket.close() # close the connection
if __name__ == '__main__':
    client_program()