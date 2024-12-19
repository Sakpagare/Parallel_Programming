#include<stdio.h>
#include<omp.h>
#define N 5

int
main ()
{
int a[N];
for(int i =0;i<N;i++){
a[i] = i+1;
} 

#pragma omp parallel num_threads(N)
  {
int tid =omp_get_thread_num();
printf("thread number:%d array element: %d\n",tid,a[tid]);
  }
  return 0;

}
