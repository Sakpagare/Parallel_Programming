#include<stdio.h>
#include<omp.h>
#define N 10
#define T 10

int
main ()
{
  int sum=0;

#pragma omp parallel num_threads(4)
  {
 #pragma omp for    
for (int i = 0; i < N; i++)
      {
     sum+=i;
      }

  }
 printf("Sum of %d number : %d\n",N,sum);
  return 0;

}
