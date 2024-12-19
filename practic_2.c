#include<stdio.h>
#include<omp.h>

int
main ()
{
  int a = 5;
#pragma omp parallel num_threads(4)	// it will create 20 thread by using cluase
  {
    if (omp_get_thread_num () == 0)
      {
	int b = 6;
	int tid = omp_get_thread_num ();
	int c = a + b + tid;
	printf ("Thread No. : %d ---> Addition : %d\n", tid, c);
          }

	  else if (omp_get_thread_num () == 1)
	  {
	    int b = 6;
	    int tid = omp_get_thread_num ();
	    int c = a + b + tid;
	    printf ("Thread No. : %d ---> Addition : %d\n", tid, c);
	  }
	else if (omp_get_thread_num () == 2)
	  {
	    int b = 7;
	    int tid = omp_get_thread_num ();
	    int c = a + b + tid;
	    printf ("Thread No. : %d ---> Addition : %d\n", tid, c);
	  }
	else
	  {
	    int b = 6;
	    int tid = omp_get_thread_num ();
	    int c = a + b + tid;
	    printf ("Thread No. : %d ---> Addition : %d\n", tid, c);
	  }

   }

	return 0;

   }
