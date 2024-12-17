#include<stdio.h>
#include<omp.h>

int
main ()
{
#pragma omp parallel
  {
    printf ("hello,world\n");
    printf ("HELLO WORLD!!!!!!!!\n");
  }
  return 0;
}
