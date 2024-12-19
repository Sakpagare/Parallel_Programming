#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define N 10000000
#define T 13

int
main ()
{
  long long *arr1;
  long long *arr2;
  long long *result;
  long long *serialsum;
  arr1 = malloc (sizeof (long long) * N);
  arr2 = malloc (sizeof (long long) * N);
  serialsum = malloc (sizeof (long long) * N);
  result = malloc (sizeof (long long) * N);
  double parallelTime, serialTime;
  double startTime = omp_get_wtime ();
  for (long i = 0; i < N; i++)
    {
      arr1[i] = i + 1;
      arr2[i] = i + 1;
    }

#pragma omp parallel for  num_threads(T)
  for (long i = 0; i < N; i++)
    {
      result[i] = arr1[i] + arr2[i];
    }

  double endTime = omp_get_wtime ();
  parallelTime = endTime - startTime;

  startTime = omp_get_wtime ();
  for (long i = 0; i < N; i++)
    {
      serialsum[i] = arr1[i] + arr2[i];
    }
  endTime = omp_get_wtime ();
  serialTime = endTime - startTime;

  printf ("Paralle Time  = %lf\n", parallelTime);
  printf ("Serial Time  = %lf\n", serialTime);

  for (long i = N - 5; i < N; i++)
    {
      printf ("%lld ", result[i]);

    }
  printf ("\n ");


  return 0;
free(arr1);
free(arr2);
free(result);
free(serialsum);
}
