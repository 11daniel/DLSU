import os
import threading
from socket import *
from datetime import datetime
import sys

# Directory to store uploaded files
UPLOAD_DIR = 'files' #replace with actual directory
if not os.path.exists(UPLOAD_DIR):
    os.makedirs(UPLOAD_DIR)

CLIENTS = ['Unknown']

def handle_client(connectionSocket, client_name):
    while True:
        try:
            # Receive the request from the client
            request = connectionSocket.recv(1024).decode()
            if not request:
                break  # No request means the client has disconnected
            command = request.split()[0]

            if command == 'UPLOAD':
                if client_name == 'Unknown':
                    connectionSocket.send(b'Error: Unregistered User')
                    continue
                else:
                    connectionSocket.send(b'Registered User')
                    
                filename = request.split()[1]
                file_path = os.path.join(UPLOAD_DIR, filename)
                with open(file_path, 'wb') as file:
                    while True:
                        data = connectionSocket.recv(1024)
                        print(data)
                        if data == b'EOF':
                            break
                        file.write(data)
                # Get the current date and time
                now = datetime.now()

                print(f"{client_name} {now}: Uploaded {filename}")

            elif command == 'DOWNLOAD':
                if client_name == 'Unknown':
                    connectionSocket.send(b'Error: Unregistered User')
                    continue
                else:
                    connectionSocket.send(b'Registered User')
                filename = request.split()[1]
                file_path = os.path.join(UPLOAD_DIR, filename)
                if os.path.exists(file_path):
                    connectionSocket.send(b'FILE EXISTS')
                    with open(file_path, 'rb') as file:
                        while True:
                            data = file.read(1024)
                            print(data)
                            if not data:
                                break
                            connectionSocket.send(data)
                    connectionSocket.send(b'EOF')  # Signal the end of the file transfer
                    print(f"File {filename} sent successfully.")
                else:
                    connectionSocket.send(b'Error: File not found in server.')

            elif command == 'LEAVE':
                print('A connection has been closed')
                break

            elif command == 'DIR':
                if client_name == 'Unknown':
                    connectionSocket.send(b'Error: Unregistered User')
                    continue
                else:
                    connectionSocket.send(b'Registered User')
                # List all entries in the directory
                entries = os.listdir(UPLOAD_DIR)
                # Filter out only files
                files = [entry for entry in entries if os.path.isfile(os.path.join(UPLOAD_DIR, entry))]

                # Convert the list of files to a string
                files_string = "\n".join(files)  # Join the list into a single string

                # Send the string over the socket
                connectionSocket.send(files_string.encode())  # Encode the string to bytes

            elif command == 'REGISTER':
                name = request.split()[1]
                global CLIENTS
                if name not in CLIENTS:
                    CLIENTS = [name if client == client_name else client for client in CLIENTS]
                    client_name = name
                    connectionSocket.send(f'Welcome {client_name}!'.encode())
                    print(f'Welcome {client_name}!')
                else:
                    connectionSocket.send(b'Error: Registration failed. Handle or alias already exists.')
                    print(f'Failed to register {client_name} to {name}.')
                    
        except Exception as e:
            print(f'An error occurred: {e}')
            break  # Exit loop if an error occurs

    connectionSocket.close()  # Ensure the socket is closed when done

def start_server():
    serverSocket = socket(AF_INET, SOCK_STREAM)
    serverSocket.bind(('127.0.0.1', 12345))
    serverSocket.listen()
    print('The server is ready to receive')
    
    while True:
        connectionSocket, addr = serverSocket.accept()
        client_name = connectionSocket.recv(1024).decode()
        print(f'User {client_name} has connected to the Server!')

        connectionSocket.send(b'Connection to the File Exchange Server is successful!')

        client_thread = threading.Thread(target=handle_client, args=(connectionSocket,client_name))
        client_thread.start()

if __name__ == '__main__':
    start_server()
