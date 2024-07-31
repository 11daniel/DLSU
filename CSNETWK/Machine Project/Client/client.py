import os
from socket import *

UPLOAD_DIR = 'files'
if not os.path.exists(UPLOAD_DIR):
    os.makedirs(UPLOAD_DIR)

def upload_file(clientSocket, filename):
    try:
        file_path = os.path.join(UPLOAD_DIR, filename)
        if os.path.exists(file_path):
            clientSocket.send(f'UPLOAD {filename}'.encode())
            response = clientSocket.recv(1024).decode()
            
            if response == 'Error: Unregistered User':
                print(response)
                return
            
            file_path = os.path.join(UPLOAD_DIR, filename)
            with open(file_path, 'rb') as file:
                while True:
                    data = file.read(1024)
                    print(data)
                    if not data:
                        break
                    clientSocket.send(data)
            clientSocket.send(b'EOF')  # Signal the end of the file transfer
            print(f"File {filename} sent successfully.")
        else:
            print("Error: File not found.")
    except Exception as e:
        print(f'An error occurred: {e}')

def download_file(clientSocket, filename):
    try:
        clientSocket.send(f'DOWNLOAD {filename}'.encode())
        response = clientSocket.recv(1024).decode()
        
        if response == 'Error: Unregistered User':
            print(response)
            return

        response = clientSocket.recv(1024).decode()
        if response == 'FILE EXISTS':
            file_path = os.path.join(UPLOAD_DIR, filename)
            with open(file_path, 'wb') as file:
                while True:
                    data = clientSocket.recv(1024)
                    print(data)
                    if data == b'EOF':
                        break
                    file.write(data)
            print(f"File received from Server: {filename}")
        else:
            print(response)
    except Exception as e:
        print(f'An error occurred: {e}')

def dir_files(clientSocket):
    try:
        clientSocket.send('DIR'.encode())
        response = clientSocket.recv(1024).decode()
        
        if response == 'Error: Unregistered User':
            print(response)
            return

        filenames = clientSocket.recv(1024).decode()
        print('Server Directory:')
        print(filenames)
    except Exception as e:
        print(f'An error occurred: {e}')

def register_name(clientSocket, name, client_name):
    try:
        clientSocket.send(f'REGISTER {name}'.encode())
        response = clientSocket.recv(1024).decode()
        print(response)
        if response != 'Error: Registration failed. Handle or alias already exists.':
            return name
        else:
            return client_name
        
    except Exception as e:
        print(f'An error occurred: {e}')

def param_invalid():
    print('Error: Command parameters do not match or is not allowed.')
    
def print_help():
    print("""
Connect to the server application               /join <server_ip_add> <port>

Disconnect to the server application            /leave

Register a unique handle or alias               /register <handle>

Send file to server                             /store <filename>

Request directory file list from a server       /dir

Fetch a file from a server                      /get <filename>

Request command help to output all Input        /?
Syntax commands for references
""")
    
def start_client():
    clientSocket = socket(AF_INET, SOCK_STREAM)
    client_name = 'Unknown'

    while True:
        print('Please enter your input:')
        client_input = input()
        content = client_input.split()
        cmd = content[0]

        match cmd:
            case '/join':
                if len(content) == 3:
                    try:
                        server_name = client_input.split()[1]
                        server_port = int(client_input.split()[2])
                        # Attempt to connect to the server
                        clientSocket.connect((server_name, server_port))
                        clientSocket.send(str(client_name).encode())  # Convert to bytes using encode

                        response = clientSocket.recv(1024).decode()
                        print(response)
                    except OSError as e:
                        # Handle the error if the connection fails
                        print('Error: Connection to the Server has failed! Please check IP Address and Port Number.')
                else:
                    param_invalid()

            case '/leave':
                if len(content) == 1:
                    try:
                        # Close the socket
                        clientSocket.send(f'LEAVE {client_name}'.encode())  # Convert to bytes using encode
                        clientSocket.close()
                        print('Connection closed. Thank you!')
                        break
                    except Exception as e:
                        print('Error: Disconnection failed. Please connect to the server first.')
                else:
                    param_invalid()

            case '/register':
                if len(content) == 2:
                    try:
                        name = client_input.split()[1]
                        client_name = register_name(clientSocket, name, client_name)
                    except Exception as e:
                        print(f'An error occurred: {e}')
                else:
                    param_invalid()
                    
            case '/store':
                if len(content) == 2:
                    filename = client_input.split()[1]
                    upload_file(clientSocket, filename)
                else:
                    param_invalid()
            case '/dir':
                if len(content) == 1:
                    dir_files(clientSocket)
                else:
                    param_invalid()
            case '/get':
                if len(content) == 2:
                    filename = client_input.split()[1]
                    download_file(clientSocket, filename)
                else:
                    param_invalid()
            case '/?':
                if len(content) == 1:
                    print_help()
                else:
                    param_invalid()
            case _:
                print('Error: Command not found.')

if __name__ == '__main__':
    start_client()
