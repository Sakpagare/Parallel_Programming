#include<stdio.h>
#include<omp.h>
#define N 10000000000
#define T 1500


int
main ()
{
 long long add = 0;
  long long sum[T]={0};
 // long arr[N];
  //long localsum;
  //for (long i = 0; i < N; i++)
   // {
     // arr[i] = i + 1;
   // }
#pragma omp parallel for  num_threads(T)

    for (long long i = 1; i <= N; i++)
      {
    sum[omp_get_thread_num ()] += i;
      }
  
for (int i = 0; i < T; i++)
    {
      add += sum[i];
    }

  printf ("Sum using manual reduction: %lld\n", add);
  return 0;
}
