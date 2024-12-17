#include<stdio.h>
#include<omp.h>

void task1(int i){
      printf("executing task1 with thread= %d\n",i);
}

void task2(int i){
      printf("executing task2 with thread= %d\n",i);
 }


int main(){
   #pragma omp parallel num_threads(2)
   {
     int tid = omp_get_thread_num();
      if(tid ==0){
         task1(tid);
      }else{
        task2(tid);
      }
}
return 0;
}
