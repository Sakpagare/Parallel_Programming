#include<stdio.h>
#include<omp.h>
#define N 10000
#define T 30

int
main ()
{
  long sum = 0;

  double startTime = omp_get_wtime ();
#pragma omp parallel for  num_threads(T)
  for (int i = 1; i <= N; i++)
    {
#pragma omp atomic update	// atomic update will do read and write operation simulataneously and used for value updation
      sum += i;
    }
  double endTime = omp_get_wtime ();
  double parallelTime = endTime - startTime;


  startTime = omp_get_wtime ();
#pragma omp parallel for  num_threads(T)
  for (int i = 1; i <= N; i++)
    {
#pragma omp critical
      sum += i;
    }
  endTime = omp_get_wtime ();

  double serialTime = endTime - startTime;
  printf ("Sum using manual reduction: %ld\n", sum);
  printf ("parallel time using atomic operation: %lf\n", parallelTime);
  printf ("parallel time without atomic operation :  %lf\n", serialTime);
  return 0;
}
