#include<stdio.h>
#include<omp.h>

int main(){
    int a = 10;

    #pragma omp parallel num_threads(4)
   {
     int tid = omp_get_thread_num();
     int c , b=3;
     c = a +b +tid;
      if(tid == 0) {
        //c = a +b + tid;
        printf("the tid : %d with sum %d\n",tid,c);
      }else if(tid == 1){
        // c = a + b + tid;
          printf("the tid : %d with sum %d\n",tid,c);
     }else if(tid == 2){
        b = 6;
        //c  = a + b + tid;
         printf("the tid : %d with sum %d\n",tid,c);
     }else if(tid== 3){
         //c = a + b + tid;
         printf("the tid : %d with sum %d\n",tid,c);
     }
   }
  return 0;
}

