#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) 
{
int nthreads, tid, i, count, flag;

omp_lock_t locka;

/* Initialize the lock */
omp_init_lock(&locka);


/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel shared(nthreads, locka, count, flag) private(tid)
  {

  /* Obtain thread number and number of threads */
  tid = omp_get_thread_num();
  #pragma omp master
    {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    }
  printf("Thread %d starting...\n", tid);
  #pragma omp barrier
flag=0;
count =0;
while (flag !=1){
  #pragma omp sections 
    {
    #pragma omp section
      {
      printf("A-Thread %d produzindo \n",tid);
      omp_set_lock(&locka);
      if (count <10)
      count++;
       else flag = 1;
      omp_unset_lock(&locka);
       }

    #pragma omp section
      {
      printf("B-Thread %d produzindo \n",tid);
      omp_set_lock(&locka);
      if (count <10)
      count++;
       else flag = 1;
      omp_unset_lock(&locka);
       }
    #pragma omp section
      {
      printf("Thread %d consumindo\n",tid);
      omp_set_lock(&locka);
      if (count >0)
        count--;
      omp_unset_lock(&locka);
      }
     }  /* end of sections */
  }  /* end of parallel region */
}/* end while */
}


