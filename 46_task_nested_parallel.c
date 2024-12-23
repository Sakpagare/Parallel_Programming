#include<stdio.h>
#include<omp.h>
#define N 100
int
main ()
{
  int a[N];
  long sum = 0;
  long sqrsum = 0;
  for (int i = 0; i < N; i++)
    {
      a[i] = i + 1;
    }
  omp_set_nested (1);
#pragma omp parallel num_threads(2)
  {

#pragma omp sections
      {
#pragma omp section
	{
	  for (int i = 0; i < N; i++)
	    {
	      sqrsum += a[i] * a[i];
	    }

	  printf ("Level 2 : Id %d square sum:%ld\n", omp_get_thread_num (),
		  sqrsum);
	}

#pragma omp section
	{
	  for (int i = 0; i < N; i++)
	    {
	      sum += a[i];
	    }

	  printf ("Level 3 : Id %d sum : %ld\n", omp_get_thread_num (), sum);
	}
      }
  }
  return 0;
}
