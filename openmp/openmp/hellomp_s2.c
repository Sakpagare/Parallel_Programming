#include<stdio.h>
#include<omp.h>

int
main ()
{
#pragma omp parallel
  {

#pragma omp task
    {
      printf ("Hello world\n");
    }


#pragma omp task
    {
      printf ("Hello world!!!!!!!!!\n");
    }

  }
  return 0;
}
