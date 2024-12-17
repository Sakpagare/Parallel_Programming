#include<stdio.h>
#include<omp.h>

int main(){
     int a = 5;
     int b = 456;
     #pragma omp parallel default(none) shared(a) private(b) num_threads(4)
     {
        printf("inside a: %d by tid : %d : %p\n",a,omp_get_thread_num(),&a);
     }
     printf("after a: %d : %p\n",a,&a);
     return 0;
} 
