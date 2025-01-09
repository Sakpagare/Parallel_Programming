#include<stdio.h>
#include<omp.h>


int main(){
   int a =5;
   #pragma omp parallel num_threads(10)
   {
    int tid = omp_get_thread_num();
    if(tid == 0 || tid==9){
      int a = 7;
      printf("the tid :%d with a : %d\n",tid,a);
      }else{
        printf("the tid : %d with a %d\n",tid,a);
       }
   }
  printf("the value of a: %d\n",a);
 return 0;
}
   
