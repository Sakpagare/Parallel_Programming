#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define N 100000
#define T 13

int main(){
    long arr1[N]={0},arr2[N]={0},result[N]={0};
     
   double parallelTime , serialTime ;
    double startTime = omp_get_wtime();
      for(int i = 0; i < N; i++){
           arr1[i]=i+1;
            arr2[i]=i+1;
        }

     #pragma omp parallel for  num_threads(T)
       for(int i = 0; i < N; i++){
            result[i]=arr1[i]+ arr2[i];
        }
   
    double endTime = omp_get_wtime();
    parallelTime = endTime - startTime;
   
   double start = omp_get_wtime();
      long serialsum[N] ={0} ;
        for(int i = 0; i < N; i++){
            serialsum[i]=arr1[i]+ arr2[i];
        }
    double end = omp_get_wtime();
    serialTime = end- start;

    printf("Paralle Time  = %lf\n", parallelTime);
    printf("Serial Time  = %lf\n", serialTime);
    
    for(int i = N - 20; i < N; i++){
           printf("%d ",result[i]);
          
        }
	

    return 0;
}
