#!/usr/bin/env python

import signal
import socket
import sys

UDP_IP = "127.0.0.1"
UDP_PORT = 12345

class colors:
    blue = '\033[94m'
    green = '\033[92m'
    yellow = '\033[93m'
    red = '\033[91m'
    end = '\033[0m'

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def signal_handler(signal, frame):
        print('Exiting...' + colors.end)
        sock.close()
        sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)
sock.bind((UDP_IP, UDP_PORT))

if __name__ == '__main__':
    print (colors.green + "Listening for syslogs on {0}:{1}".format(UDP_IP, UDP_PORT))
    while True:
        data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
        print (colors.yellow + "Remote syslog from ({0}:{1}): ".format(addr[0], addr[1]) + colors.end + "{0}".format(data[:-1]))
