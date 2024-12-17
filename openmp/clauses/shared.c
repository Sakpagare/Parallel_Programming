#include<stdio.h>
#include<omp.h>

int main(){

    int a=7;
    #pragma omp parallel shared(a) num_threads(5)
    {
      printf("inside a : %d ... tid : %d\n",a,omp_get_thread_num());
    }
    printf("after : %d\n",a);
    return 0;

}
     
