#include<stdio.h>
#include<omp.h>
int main(){
     #pragma omp parallel num_threads(6)
     {
        printf("Hello form thread : %d\n",omp_get_thread_num());
     }
         

   return 0;
}
