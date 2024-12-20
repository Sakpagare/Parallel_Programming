#include<stdio.h>
#include<omp.h>
#define N 1000000
#define T 13


int
main ()
{
  long arr[N];
  long add = 0;
  long sum=0;
  for (long i = 0; i < N; i++)
    {
      arr[i] = i + 1;
    }
  long chunk_size = N / T;
#pragma omp parallel num_threads(T)
  {
    int tid = omp_get_thread_num ();
    long localsum = 0;
    long start = tid * chunk_size;
    long end = start + chunk_size;
    if (tid == T - 1)
      {
	end = N;
      }
    for (long i = start; i < end; i++)
      {
	localsum += arr[i];
      }
  #pragma omp critical
    sum += localsum;
  }


  printf ("Sum using manual reduction: %ld\n", sum);
  return 0;
}
