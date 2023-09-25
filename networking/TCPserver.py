import socket

host ='localhost'
port=10000
size=1024
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)  
s.connect((host,port))
data=s.recv(size)
if len(data):
 print('received: ',data.decode('UTF-8'))
data="message goes here"
while 1:
	message=input('input lowercase sentence ')
	s.send(message.encode('utf-8'))
	data=s.recv(size)
	print('received :', data.decode('utf-8'))
	if message=="quit":
		data=''

s.close()
	