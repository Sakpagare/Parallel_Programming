#include<stdio.h>
#include<omp.h>

int main(){
      omp_set_num_threads(14);
      #pragma omp parallel num_threads(2)
      {
        printf("Hello from first parallel region\n");
      }

     #pragma omp parallel
     {
       printf("Hello from second parallel region\n");
     }


    return 0;
}
