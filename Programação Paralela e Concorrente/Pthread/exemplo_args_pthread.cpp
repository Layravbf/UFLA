#include <iostream>

#include "pthread.h"
using namespace std;

struct argum{
int e;
int k;
};

void* primo(void* b){
	
	argum *elemento = (argum*) b;
	cout <<elemento->e << " " << elemento->k << endl;
	
}

int main(){
	pthread_t tid=10;
    argum *a = new argum;
    a->e=10;
    a->k=20;
   
    pthread_create(&tid, NULL, primo, a);
    pthread_join (tid, NULL);
    return 0;
}

