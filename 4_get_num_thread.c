#include<stdio.h>
#include<omp.h>
int
main ()
{
  omp_get_num_threads ();
    printf (" number of threads before start : %d \n",omp_get_num_threads());
  omp_set_num_threads (10);	// it will create 4 threads by using routines
#pragma omp parallel num_threads(15)	// it will create 20 thread by using cluase
  {
    printf ("Hello World Process 1 \n");
    printf ("Hello World Process 1 number of threads : %d \n",omp_get_num_threads());
  }
#pragma omp parallel num_threads(20)	// it will create 20 thread by using cluase
  {
    printf ("Hello World Process 2 :\n");
    printf ("Hello World Process 2 number of threads: %d \n",omp_get_num_threads());
  }
    printf ("Total number of threads after parallel region :  %d \n",omp_get_num_threads());
  return 0;

}
