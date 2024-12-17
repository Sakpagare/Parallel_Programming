#include<stdio.h>
#include<omp.h>

int main(){
    int a = 5;
    #pragma omp parallel private(a) num_threads(4)
    {  
       int tid = omp_get_thread_num();
       if(tid==3) a=7;
       printf("inside a : %d by tid : %d\n",a,tid);
       
    }
    printf("After a = %d\n",a);
}
