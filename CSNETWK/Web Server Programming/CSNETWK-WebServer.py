#import socket module
from socket import *
import sys # In order to terminate the program

serverSocket = socket(AF_INET, SOCK_STREAM)
#Prepare a sever socket
#Fill in start
serverSocket.bind(('localhost', 9090))
serverSocket.listen(1)
#Fill in end


while True:
    #Establish the connection
    print('CSNETWK Web Server is ready to serve...')
    connectionSocket, addr = serverSocket.accept() #Fill in start     #Fill in end
    try:
        message =  connectionSocket.recv(1024).decode()#Fill in start #Fill in end

        filename = message.split()[1]
        f = open(filename[1:])
        
        outputdata =  f.read()#Fill in start #Fill in end
        #Send one HTTP header line into socket
        #Fill in start
        status_line = "HTTP/1.1 200 OK\r\n"
        headers = "Content-Type: text/html\r\n"
        headers += f"Content-Length: {len(outputdata)}\r\n"
        headers += "\r\n"  # Blank line to indicate end of headers

        http_response = status_line + headers

        connectionSocket.sendall(http_response.encode())
        # Fill in end
        #Send the content of the requested file to the client
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
       
        connectionSocket.send("\r\n".encode())
        connectionSocket.close()
        
        break
    
    except IOError:
        #Send response message for file not found
        #Fill in start
        outputdata = """
        <!DOCTYPE html>
        <html>
        <head>
        <title>
        CSNETWK - Web Server Programming</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <style>
        body {background-color:#ffffff;background-repeat:no-repeat;background-position:top left;background-attachment:fixed;}
        h1{font-family:Arial, sans-serif;color:#000000;background-color:#ffffff;}
        p {font-family:Georgia, serif;font-size:14px;font-style:normal;font-weight:normal;color:#000000;background-color:#ffffff;}
        </style>
        </head>
        <body>
        <h1>ERROR 404</h1>
        <p></p>
        </body>
        </html>
        """
        
        status_line = "HTTP/1.1 404 Not Found\r\n"
        headers = "Content-Type: text/html\r\n"
        headers += f"Content-Length: {len(outputdata)}\r\n"
        headers += "\r\n"
        
        http_response = status_line + headers
        
        connectionSocket.sendall(http_response.encode())
        
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
       
        connectionSocket.send("\r\n".encode())
        #Fill in end
       
        #Close client socket
        #Fill in start
        connectionSocket.close()
        #Fill in end
        break\

serverSocket.close()
sys.exit()  #Terminate the program after sending the corresponding data