import socket
from threading import Thread
from datetime import datetime
from colorama import Fore, init, Back

init()

client_color = Fore.BLUE

SERVER_HOST = "127.0.0.1"
SERVER_PORT = 4443

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print(f"[*] Connectando a {SERVER_HOST}:{SERVER_PORT}...")

s.connect((SERVER_HOST, SERVER_PORT))
print("[+] Conectado.")

name = input("Digite seu nome: ")

def listen_for_messages():
    while True:
        data = s.recv(1024).decode()
        print(data)

def send_message():
    while True:
        msg = input()
        date_now = datetime.now().strftime('%Y-%m-%d %H:%M:%S') 
        message = f"{client_color}[{date_now}] {name} <> {msg}{Fore.RESET}"
        print(message)
        s.send(message.encode())
        if(msg == 'SAIR' or msg == 'sair'):
            print(f'{name} desconectou.')
            break
    s.close()

t1 = Thread(target=send_message)
t2 = Thread(target=listen_for_messages)

t1.daemon = True
t2.daemon = True
t1.start()
t2.start()

t1.join()
t2.join()

