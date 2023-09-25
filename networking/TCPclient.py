import socket
import sys  
serverPort =12000
sock =socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_address=('localhost',10000)
print ('starting up on %s port %s' % server_address)
sock.bind(server_address)
sock.listen(1)
print ("The server is ready to receive ")
while 1:
	print ("waiting for a connection")
	connection, client_address =sock.accept()
	try:
		print ("client connected",client_address)
		data="welcome to the echo server "
		connection.sendall(data.encode("UTF-8"))
		while True :
			data=connection.recv(1024)
			print('received"%s"'% data.decode("UTF-8"))
			if data:
				connection.sendall(data.upper())
			else:
				break
	finally :
		connection.close()
	