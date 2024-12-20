#include<stdio.h>
#include<omp.h>
#define N 10000
#define T 30


int
main ()
{
  long sum = 0;
#pragma omp parallel for  num_threads(T)
   for (int i = 1; i <= N; i++)
      {
  #pragma omp critical
    sum += i;
      }
  

  printf ("Sum using manual reduction: %ld\n", sum);
  return 0;
}
