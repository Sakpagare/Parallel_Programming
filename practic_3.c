#include<stdio.h>
#include<omp.h>
int a=5;
void task(int b)  {
        int tid = omp_get_thread_num ();
        int c = a + b + tid;
        printf ("Thread No. : %d ---> Addition : %d\n", tid, c);
      }
int
main ()
{
 // int a = 5;
#pragma omp parallel num_threads(4)
  {
    if (omp_get_thread_num () == 2)
     task(7);
    else
     task(6);

  }

  return 0;

}
