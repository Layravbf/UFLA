import socket
from threading import Thread
from datetime import datetime
from colorama import Fore, init, Back
import re

HOST = '127.0.0.1'
PORT = 4443

init()

server_color = Fore.GREEN

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()

print('Aguardando conexão de um cliente')

def listen_clients(c):
    while True:
        try:
            message = c.recv(1024).decode()
        except Exception as e:
            print(f'[!] Error: {e}')
        else:
            regex = re.search('(?:^|\W)sair(?:$|\W)', message)
            if regex:
                print('Fechando conexão')
                s.close()
                break
            else:
                print(message)

		
def enviar_message(conn):
    while True:
        msg = input()
        date_now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        msg = f"{server_color}[{date_now}] Server <> {msg}{Fore.RESET}"
        print(msg)
        conn.send(msg.encode())
	
while True:
    client_socket, ender = s.accept()
    
    print('Conectado em', ender)

    t1 = Thread(target=listen_clients, args=(client_socket,))
    t2 = Thread(target= enviar_message, args=(client_socket,))

    t1.daemon = True
    t2.daemon = True
    t1.start()
    t2.start()

    t1.join()
    t2.join()

