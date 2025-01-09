#include<stdio.h>
#include<omp.h>


int main(){

    int a = 9;
    #pragma omp parallel num_threads(20)

    {
      int tid = omp_get_thread_num();
      if(tid == 0){
          a=7;
      }
      printf("thread : %d..... a : %d\n",tid,a);
      
    } 
    return 0;
}
      
