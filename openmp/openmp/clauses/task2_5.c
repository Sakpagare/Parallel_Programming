#include<stdio.h>
#include<omp.h>

#define N 21
#define T 10

int main(){
     int a[N];
     int b[N];
     for(int i=0;i<N;i++) a[i] = i + 1;
     int c[N]; 
     #pragma omp parallel num_threads(4)
     {
      for(int i=0;i<N;i++){
          c[i] = a[i] + b[i];
          //printf("%d ",&c[i]);
      }
      printf("\n");
  }
     return 0;
}
