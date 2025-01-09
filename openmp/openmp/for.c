#include<stdio.h>
#include<omp.h>

int
main ()
{
#pragma omp parallel for
  {
    int a = 5;
    int b = 4;
    int sum = 0;
    for (int i = 0; i < 5; i++)
      {
	sum = a + b;
      }

    printf ("Sum is :%d\n", sum);
  }
  return 0;
}
