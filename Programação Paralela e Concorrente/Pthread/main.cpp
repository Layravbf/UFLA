#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;
#define NUM_THREADS     5

const int n = 10;
int vet[n], k;
void *multiplo(void *param);
pthread_mutex_t mutex;

struct args{
	int inicio;
	int fim;
	int k
};

int main(int argc, char **argv){
	
	//pthread_t tid1, tid2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_t tid[NUM_THREADS];
	pthread_mutex_init(&mutex, NULL);
	
	int t=0;
	long k=2, cont = 0;
	for (cont =0;cont <= n;cont++){
		vet[cont] = cont;
	}
	
	args params;
	params
	
	int inicio, fim;
	
	
	while (k*k <=n){
		/*Cria thread tid1*/
		inicio = idThread*(n/NUM_THREADS) ;
		fim = inicio + n/NUM_THREADS;
		params.inicio = inicio;
		params.fim = fim;
		params.k = k;
		pthread_create(&tid[t],NULL,multiplo,(void *) params);
		k++;
		while(vet[k] == -1){
			k++;
		}
		//pthread_mutex_lock(&mutex);
		t++;
		//pthread_mutex_unlock(&mutex);
	}
	
	//long id;
	//pthread_create(&tid26,&attr,print,(void *) id);
	
	//Thread principal espera até thread tid1 terminar execução
	//pthread join(tid1, NULL);

	
	for(cont=2; cont<=n; cont++){
		if(vet[cont]!=-1)
			cout << cont << endl;
	}
	
	//pthread_mutex_destroy(&mutex);
	exit(0);
}

void *multiplo(void *param){
	
	args p = (args)(param);
	int k = p.k;
	int inicio = p.inicio, fim = p.fim;
	long cont;
	for (cont=inicio; cont <= fim;cont=cont+k){
		vet[cont]=-1;
	}
	pthread_exit(NULL);
}
