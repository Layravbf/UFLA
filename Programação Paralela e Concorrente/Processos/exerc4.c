#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int pid1, pid2, pid3, pid4;
	sleep(14);
	//cria processo filho 1 apos os 14 "anos"
	printf("Filho 1 nasce aos 14 anos\n");
	pid1 = fork();
	if (pid1 == 0) {
		sleep(12);//O pai é avô aos 26 anos
		printf("Aos 26 anos, torna-se avô do filho do primeiro filho\n");
		pid3 = fork();
		if (pid3 == 0) {
			sleep(12);
			printf("Primeiro neto morre aos 12 anos\n");
			exit(0); //Encerra processo, neto 1 morre aos 12 anos
		}else{
			sleep(18); 
			printf("Aos 30, o primeiro filho morre\n");
			exit(0); //Encerra processo, filho morre aos 30 anos
		}
	}else{ // Processo pai
		sleep(2); //apos 14 anos espera mais 2, completando os 16 anos para o 2 filho
		printf("Aos 16 anos, nasce o filho 2\n");
		pid2 = fork();
		if (pid2 == 0) {
			sleep(14); //O pai é avô novamente aos 30 anos
			printf("Aos 30, torna-se avô do filho do segundo filho\n");
			pid4 = fork();
			if (pid4 == 0){
				sleep(14);
				printf("Segundo neto morre aos 14 anos\n");
				exit(0); //Encerra processo, neto morre aos 14 anos
			}else{
				sleep(16);
				printf("Aos 30, o segundo filho morre\n");
				exit(0); //Encerra processo, filho morre aos 30 anos
			}
		}else{
			sleep(44); //Pai morre aos 60 anos
			printf("Aos 60, o pai morre\n");
		}
	}
	
	return 0;
}
