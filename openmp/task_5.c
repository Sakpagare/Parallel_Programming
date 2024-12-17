#include<stdio.h>
#include<omp.h>
void task1(int a,int b,int tid){
     int c = a + b + tid;
    printf("value of c = %d for thread is %d\n",tid,c);
}

int main(){
      int a = 6;
      #pragma omp parallel num_threads(4)
      {
         int b = 6;
         int tid = omp_get_thread_num();
         if(tid == 2) b =7;
           task1(a,b,tid);
      }

   return 0;
}

