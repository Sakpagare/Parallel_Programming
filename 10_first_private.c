#include<stdio.h>
#include<omp.h>
int
main ()
{
int a=5;

#pragma omp parallel firstprivate(a)  num_threads(4)
  {

  printf("thread id: %d , value of A :%d : %p\n",omp_get_thread_num(),a,&a);
  }
  printf("value of A after parallel region :%d : %p\n",a,&a);
  return 0;

}
