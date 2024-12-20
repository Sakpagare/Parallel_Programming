#include<stdio.h>
#include<omp.h>
#define N 20
#define T 6
int
main ()
{
  int a[N] = { 1343, 100, 500000, 322, 4444, 544, 300, 7000000, 400, 3244 };
#pragma omp parallel for schedule(guided, 3) num_threads(T)
  for (int i = 0; i < N; i++)
    {
      printf ("thread\t%d\t:\ti\t%d\n", omp_get_thread_num (), i);
      for (int j = 0; j < a[i]; j++);
    }
}
