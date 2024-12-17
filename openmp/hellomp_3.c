#include<stdio.h>
#include<omp.h>


int
main ()
{
  omp_set_num_threads (5);
#pragma omp parallel num_threads(6)
  {
    printf ("hello world\n");
  }

  return 0;
}
