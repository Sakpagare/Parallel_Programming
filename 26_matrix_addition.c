#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define row 100
#define column 100
#define T 13

int
main ()
{
  long long *arr1;
  long long *arr2;
  long long *result;
  long long *serialsum;
  arr1 = malloc (sizeof (long long) * row * column);
  arr2 = malloc (sizeof (long long) * row * column);
  serialsum = malloc (sizeof (long long) * row * column);
  result = malloc (sizeof (long long) * row * column);
  double parallelTime, serialTime;
  double startTime = omp_get_wtime ();
  for (long i = 0; i < row * column; i++)
    {
      arr1[i] = i + 1;
      arr2[i] = i + 1;
    }

#pragma omp parallel for  num_threads(T)
  for (long i = 0; i < row * column; i++)
    {
      result[i] = arr1[i] + arr2[i];
      printf ("\n");
    }

  double endTime = omp_get_wtime ();
  parallelTime = endTime - startTime;

  printf ("Paralle Time  = %lf\n", parallelTime);
  for (long i = 0; i < row; i++)
    {
      for (long j = 0; j < column; j++)
	{
	  int idx = i * column + j;
	  printf ("%d ", arr1[idx]);
	}
      printf ("\n ");
    }
  printf ("\n ");

  for (long i = 0; i < row; i++)
    {
      for (long j = 0; j < column; j++)
	{
	  int idx = i * column + j;
	  printf ("%d ", arr2[idx]);
	}
      printf ("\n ");
    }
  printf ("\n ");



  for (long i = 0; i < row; i++)
    {
      for (long j = 0; j < column; j++)
	{
	  int idx = i * column + j;
	  printf ("%d ", result[idx]);
	}
      printf ("\n ");
    }
  printf ("\n ");


  return 0;
  free (arr1);
  free (arr2);
  free (result);
}
