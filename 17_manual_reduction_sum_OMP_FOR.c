#include<stdio.h>
#include<omp.h>
#define N 10000000
#define T 30


int
main ()
{
  long add = 0;
  long sum[T]={0};
 // long arr[N];
  //long localsum;
  //for (long i = 0; i < N; i++)
   // {
     // arr[i] = i + 1;
   // }
#pragma omp parallel for  num_threads(T)

    for (int i = 1; i <= N; i++)
      {
    sum[omp_get_thread_num ()] += i;
      }
  
for (int i = 0; i < T; i++)
    {
      add += sum[i];
    }

  printf ("Sum using manual reduction: %ld\n", add);
  return 0;
}
