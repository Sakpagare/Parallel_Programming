#include <stdio.h>
#include <omp.h>

int main() {
    
    #pragma omp parallel 
    {
        int tid = omp_get_thread_num();

        if (tid == 0) { 
           // int nthreads = omp_get_num_threads(); 
            printf("Master thread  = %d\n", tid);
        } else {
            printf("Hello from thread %d\n", tid);
        }
    }

    return 0; 

}
