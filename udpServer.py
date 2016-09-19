import socket

UDP_IP = "127.0.0.1"
UDP_PORT = 12345

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    print ("Remote syslog from ({0}:{1}): {2}".format(addr[0], addr[1], data))
