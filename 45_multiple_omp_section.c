#include<stdio.h>
#include<omp.h>
#define N 1000
#define T 10
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
#pragma omp parallel num_threads(3)
  {
#pragma omp sections
    {
#pragma omp section
      {
	for (int i = 0; i < N; i++)
	  {
	    sqrsum += a[i] * a[i];
	  }
	printf
	  ("This section is executed by thread %d and addition of square is :%ld \n",
	   omp_get_thread_num (), sqrsum);
      }


#pragma omp section
      {
	for (int i = 0; i < N; i++)
	  {
	    sum += a[i];
	  }
	printf
	  ("This section is executed by thread %d and addition is :%ld \n",
	   omp_get_thread_num (), sum);
      }
    }
  }

  return 0;
}
