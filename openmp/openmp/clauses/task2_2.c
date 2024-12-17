//divide data into number of threads
#include<stdio.h>
#include<omp.h>

#define N 100
#define T 10

int main(){
  int a[N];
  for(int i=0;i<N;i++) a[i]= i +1;

  #pragma omp parallel num_threads(T)
   {
     #pragma omp for
     for(int i=0;i<N;i++){
         printf(" %d ",a[i]);
     }
    printf("\n");
   }
return 0;
}
