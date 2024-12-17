//write a program to calculate sum of natural number
#include<stdio.h>
#include<omp.h>

#define N 5
//#define T 10

int main(){
     int a;
     int b;
    // for(int i=0;i<N;i++) a[i] = i + 1;
     int c = 0;
      c = a + b; 
     #pragma omp parallel num_threads(4)
      {
       #pragma omp for
       for(int i=1;i<N;i++){
         // c = a + b;
         // printf("%d ",c);
      }
      printf("\n");
     }
  printf("%d\n",c); 
  return 0;
}
