#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
	int var1, soma=0;
    int i;
    pid_t pid, pid1;

    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
		var1 = 20;
		for(int i = 1; i <=100; i = i + 2){
			soma += i;
		}
		printf("Soma de Impares: %d\n", soma);
        //O código aqui dentro será executado no processo filho
        printf("variavel do Filho: %d\n", var1);
        printf("pid do Filho: %d\n", getpid());
    }
    else
    {
		var1 = 10;
		for(int i = 0; i <=100; i = i + 2){
			soma += i;
		}
		printf("Soma de Pares: %d\n", soma);
        //O código neste trecho será executado no processo pai
        printf("variavel do Pai: %d\n", var1);
        printf("pid do Pai: %d\n\n", getpid());
        
        pid1 = fork();
        if(pid1 == 0){
			printf("Processo Filho 2\n");
			execlp("/usr/bin/firefox", "firefox", NULL);
		}else{
			sleep(1);
		}
    }

    printf("Esta regiao sera executada por ambos processos (%d): %d\n\n", getpid(), soma);
    scanf("%d", &i);
    printf("Digitar S para sair. ");
    exit(0);
}


