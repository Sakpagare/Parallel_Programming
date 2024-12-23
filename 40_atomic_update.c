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
  #pragma omp atomic update   // atomic update will do read and write operation simulataneously and used for value updation
    sum += i;
      }
  

  printf ("Sum using manual reduction: %ld\n", sum);
  return 0;
}
