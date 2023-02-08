#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int pid;
	pid = fork();
	
	if(pid < 0){
		fprintf(stderr, "Erro ao criar processo\n");
	}
	else if(pid == 0){
		printf("Processo filho\n");
		execlp("/usr/bin/firefox", "firefox", NULL);
	}
	
	sleep(2);
	printf("Ola");
	return 0;
}
