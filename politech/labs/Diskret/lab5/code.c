#include <stdio.h>
#include <stdlib.h>
#define SIZE 30
#define _CRT_SECURE_NO_WARNINGS
int main()
{
  int a[SIZE][SIZE]; 
  int d[SIZE]; 
  int v[SIZE]; 
  int temp, minindex, min;
  int begin_index = 0;
  system("chcp 1251");
  system("cls");
  printf("Enter Matrix:\n");
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++) {
      scanf_s("%d", &temp);
      a[i][j] = temp;
    }
  }

  for (int i = 0; i < SIZE; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }
  d[begin_index] = 0;
  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i < SIZE; i++)
    {
      if ((v[i] == 1) && (d[i] < min))
      {
        min = d[i];
        minindex = i;
      }
    }
    if (minindex != 10000)
    {
      for (int i = 0; i < SIZE; i++)
      {
        if (a[minindex][i] > 0)
        {
          temp = min + a[minindex][i];
          if (temp < d[i])
          {
            d[i] = temp;
          }
        }
      }
      v[minindex] = 0;
    }
  } while (minindex < 10000);
  printf("\nShortest distants: \n");
  for (int i = 0; i < SIZE; i++)
    printf("%3d", d[i]);
  int ver[SIZE];
  int end = 29;
  ver[0] = end + 1;
  int k = 1;
  int weight = d[end];

  while (end != begin_index)
  {
    for (int i = 0; i < SIZE; i++) 
      if (a[end][i] != 0)
      {
        int temp = weight - a[end][i];
        if (temp == d[i]) 
        {                 
          weight = temp; 
          end = i;     
          ver[k] = i + 1; 
          k++;
        }
      }
  }

  printf("\nOutput of the shortest way:");
  for (int i = k - 1; i >= 0; i--)
    printf("%3d ", ver[i]);
  return 0;
}

/*
0 7 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
7 0 5 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 5 0 3 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 3 0 8 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 8 0 5 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 5 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
4 0 0 0 0 0 0 7 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 3 0 0 0 0 7 0 3 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 3 0 0 0 0 3 0 1 0 0 0 0 7 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 4 0 0 0 0 1 0 2 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 4 0 0 0 0 2 0 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 2 0 0 0 0 0 0 7 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 2 0 0 0 0 0 0 3 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 3 0 8 0 0 0 0 5 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 7 0 0 0 0 8 0 8 0 0 0 0 6 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 4 0 0 0 0 8 0 7 0 0 0 0 6 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 7 0 7 0 0 0 0 7 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 7 0 0 0 0 7 0 0 0 0 0 0 7 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 4 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 5 0 0 0 0 1 0 3 0 0 0 0 2 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 6 0 0 0 0 3 0 1 0 0 0 0 3 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 6 0 0 0 0 1 0 1 0 0 0 0 8 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 7 0 0 0 0 1 0 5 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 7 0 0 0 0 5 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 4 0 0 0 0 0 0 3 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 3 0 3 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 3 0 4 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 8 0 0 0 0 4 0 3 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 3 0 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 1 0
*/
