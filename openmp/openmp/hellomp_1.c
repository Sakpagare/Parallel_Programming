#include<stdio.h>
//#include<omp.h>

int
main ()
{
  omp_set_num_threads (10);

#pragma omp parallel
  {
    printf ("Hello world\n");
  }


  return 0;
}