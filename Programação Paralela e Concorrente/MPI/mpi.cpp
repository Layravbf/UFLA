#include <iostream>
#include "mpi.h"
#define N 10
using namespace std;

int main(int argc, char *argv[]){
	double vetor[N];
	for(int i=0; i<N; i++){
		vetor[i] = rand()%100;
	}
	
	int nprocs, rank;
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	int sendcount = N/nprocs;
	double vetor2[N/nprocs];
	//divide os dados entre os processos
	MPI_Init(&argc,&argv); //chama o fork internamente (criar processo)
	MPI_Scatter(vetor, sendcount, MPI_DOUBLE, vetor2, sendcount,MPI_DOUBLE, source, MPI_COMM_WORLD);
	for(int i=0; i<sendcount; i++){
		cout << rank << ":" << vetor2[i] << " ";
	}
	cout << endl;
	MPI_Finalize(); 
	
	/* MPI_Scatter -> vetor inicial com os valores (10 valores)
	 * -> sendcount -> 10/num processos (quantos valores para cada processo)
	 * -> MPI_DOUBLE tipo das variaveis
	 * -> vetor2 -> recebe os valores 
	 * */
	return 0;
}
