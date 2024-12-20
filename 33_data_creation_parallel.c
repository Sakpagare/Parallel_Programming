#include<stdio.h>
#include<omp.h>
#define N 10000
#define T 13
	int
main ()
{
	long arr[N]={0};
  long long sum = 0;
#pragma omp parallel num_threads(T)
  {

#pragma omp single
    {
      for (int i = 0; i < N; i++)
	{
	  arr[i] = i + 1;
	}
    }
// at the end of single there is implicit barrier where all the threads wait to complete single block
    long long localsum = 0;
#pragma omp for
    for (int i = 0; i < N; i++)
      {
	localsum += arr[i];
      }
#pragma omp critical
    {
      sum += localsum;
    }
  }

  printf ("Calculated sum = %lld\n", sum);

  return 0;
}
