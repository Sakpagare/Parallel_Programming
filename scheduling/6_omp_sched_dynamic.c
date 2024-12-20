#include<stdio.h>
#include<omp.h>
#define N 20
#define T 3
int
main ()
{
  omp_set_schedule(omp_sched_dynamic,8); // to use this function you have to use static clause
#pragma omp parallel for schedule(runtime) num_threads(T)
  for (int i = 0; i < N; i++)
    {
      printf ("thread\t%d\t:\ti\t%d\n", omp_get_thread_num (), i);
      
    }
return 0;
}
