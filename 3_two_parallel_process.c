#include<stdio.h>
#include<omp.h>
int
main ()
{
  omp_set_num_threads (10);	// it will create 4 threads by using routines
#pragma omp parallel num_threads(15)	// it will create 20 thread by using cluase
  {
    printf ("Hello,World Process 1 \n");
  }
#pragma omp parallel num_threads(20)	// it will create 20 thread by using cluase
  {
    printf ("Hello,World Process 2 \n");
  }
  return 0;

}
