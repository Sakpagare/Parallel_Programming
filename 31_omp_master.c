#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 10000
#define T 10
int main(){
    #pragma omp parallel num_threads(T)
    {
        #pragma omp master  // statement in omp master will execute by master thread only i.e. thread 0
        {
            printf("%d have an extra statement to execute\n", omp_get_thread_num());
        }
        printf("Hi, I am thread %d\n", omp_get_thread_num());
    }
    return 0;
}
