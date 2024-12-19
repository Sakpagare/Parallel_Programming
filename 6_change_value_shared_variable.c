#include<stdio.h>
#include<omp.h>
void task(int a)  {
      int tid = omp_get_thread_num();  
      printf ("Thread No. : %d ---> Value of a : %d\n", tid, a);
      }
int
main ()
{
int a=5;

#pragma omp parallel num_threads(10)
  {
    if (omp_get_thread_num () == 0)
     {
        a=7;
	task(a);
     }
    else
     task(a);

  }
  printf("value of A after parallel region :%d\n",a);
  return 0;

}
