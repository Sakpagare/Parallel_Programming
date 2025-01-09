#include<stdio.h>
#include<omp.h>

int
main ()
{
#pragma omp parallel
  {
    int thread_id = omp_get_thread_num ();
    if (thread_id == 0)
      {
	printf ("Thread 0 is executing this block.\n");
      }
    else
      {
	printf ("other thread %d is executing this block .\n", thread_id);
      }
  }
  return 0;
}
