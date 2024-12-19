#include<stdio.h>
#include<omp.h>
#define N 1000000
#define T 1000


int
main ()
{
 long long arr[N];
  long long add = 0;
 long long sum[T];
  for (long long i = 0; i < N; i++)
    {
      arr[i] = i + 1;
    }
  long chunk_size = N / T;
#pragma omp parallel num_threads(T)
  {
    int tid = omp_get_thread_num ();
   long long localsum = 0;
    long long start = tid * chunk_size;
    long long end = start + chunk_size;
    if (tid == T - 1)
      {
	end = N;
      }
    for (long long i = start; i < end; i++)
      {
	localsum += arr[i];
	//  printf("%d\n ",localsum);
      }
    sum[tid] = localsum;
    //printf("%d\n ",sum[tid]);
  }


  for (int i = 0; i < T; i++)
    {
      add += sum[i];
    }

  printf ("Sum using manual reduction: %lld\n", add);
  return 0;
}
