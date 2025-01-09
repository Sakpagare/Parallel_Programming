#include<stdio.h>
#include<omp.h>

int main(){
        printf("Total numbers fo threads : %d\n",omp_get_num_threads());
        omp_set_num_threads(14);

       #pragma omp parallel num_threads(6)
       {
         printf("first parallel region\n");
         printf("Total numbers fo threads : %d\n",omp_get_num_threads());
       }

      #pragma omp parallel
       {
         printf("second \n");
         printf("Total numbers fo threads : %d\n",omp_get_num_threads());
       }

        printf("Total numbers fo threads : %d\n",omp_get_num_threads());
        return 0;
}

