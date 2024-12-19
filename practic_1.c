#include<stdio.h>
#include<omp.h>
void task1(){

    printf ("Hello World Process 1 number of thread:%d: \n",omp_get_thread_num()); // this routine is used to get thread id

}
void task2(){

    printf ("Hello Cdac thread:%d: \n",omp_get_thread_num()); // this routine is used to get thread id
}


int main ()
{
#pragma omp parallel num_threads(2)	// it will create 20 thread by using cluase
  {
    if(omp_get_thread_num()==0)
     task1();
    else  
      task2();
}

  return 0;

}
