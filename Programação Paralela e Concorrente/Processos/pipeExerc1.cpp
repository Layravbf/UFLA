#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(){
	int fd[2];
	pid_t pid; 
	
	// Cria pipe
	if(pipe(fd) < 0){
		cout << "Pipe nao criado" << endl;
		_exit(0);
	}
	
	// Cria processo filho
	pid = fork();

	if(pid < 0){ // Ocorreu um erro
		cerr << "Fork Falhou" << endl;
		return 1;
	}else if(pid == 0){
		char path[40];
		close(fd[1]);
		read(fd[0], path, sizeof(path));
		close(fd[0]);
		execl("/usr/bin/wc", "wc", path, NULL);
	}else{ // processo pai
		char path[40] = "/home/aluno/Documentos/entrada.txt";
		//cin >> path;
		//processo pai passa o caminho para o filho via pipe
		close(fd[0]);
		write(fd[1], &path, sizeof(path));
		close(fd[1]);
		//pai espera filho para completar execução
		wait(NULL);
		cout << "Filho completou" << endl;
	}

	return 0;
}
