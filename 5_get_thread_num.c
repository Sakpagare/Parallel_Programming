#include<stdio.h>
#include<omp.h>
int
main ()
{
#pragma omp parallel num_threads(15)	// it will create 20 thread by using cluase
  {
    printf ("Hello World Process 1 number of thread:%d: \n",omp_get_thread_num()); // this routine is used to get thread id
  }

 printf("####################################################################################################################\n");
#pragma omp parallel num_threads(20)	// it will create 20 thread by using cluase
  {
    printf ("Hello World Process 2 number of thread:%d: \n",omp_get_thread_num());
  }
  return 0;

}
