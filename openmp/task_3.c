#include<stdio.h>
#include<omp.h>


int main(){
   int a =5;
   #pragma omp parallel num_threads(4)
   {
    int tid = omp_get_thread_num();
    int b =2;
    int c = a + b + tid;
    if(tid == 2){
      int b = 4;
       c = a +b +tid;
      printf("the tid :%d with sum : %d\n",tid,c);
      }else{
        printf("the tid : %d with sum %d\n",tid,c);
       }
   }
 return 0;
}
