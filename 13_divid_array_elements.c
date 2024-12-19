#include<stdio.h>
#include<omp.h>
#define N 1000
#define T 10


int
main ()
{
  int a[N];
  for (int i = 0; i < N; i++)
    {
      a[i] = i + 1;
    }

    int chunk = (N / T);
#pragma omp parallel num_threads(T)
  {
    int tid = omp_get_thread_num ();
    int start = tid*chunk;
    int end = tid + chunk;
    if (tid == T-1)
    {  end = N; }
    for (int i = start; i < end; i++)
      {
	printf ("%d\n", a[i]);
      }

  }
  return 0;

}
