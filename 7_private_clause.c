#include<stdio.h>
#include<omp.h>
int
main ()
{
int a=5;

#pragma omp parallel private(a)  num_threads(4)
  {

  printf("thread id: %d , value of A :%d\n",omp_get_thread_num(),a);
  }
  printf("value of A after parallel region :%d\n",a);
  return 0;

}
