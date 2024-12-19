#include<stdio.h>
#include<omp.h>
int
main ()
{
  omp_set_num_threads (10);	// it will create 4 threads by using routines
#pragma omp parallel num_threads(20)	// it will create 20 thread by using cluase
  {
    printf ("Hello,World1111111111\n");
  }
  return 0;

}
