// SLL_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SLL.h"
#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
#include <string.h>

// Assume following return types while writing the code for this question.
int output1 = 0;

int smallest(int cook[], int size, int *index)
{
  int min = 0, i = 0, j = 0, k = 0;

  while (cook[j++] != 0 && min == 0 && j < size)
  {
    min = cook[j];
  }

  while (i < size)
  {
    if (cook[i] != 0 && cook[i] < min)
    {
      min = cook[i];
      k = i;
    }
    i++;
  }
  cook[k] = 0;
  *index = k;
  return min;
}

void Chef(int input1, int input2, int input3[], int input4[])
{
  int i, j, n = 0;
  while (input1)
  {
    int minT1 = smallest(input3, input2, &i);
    input1 = input1 - minT1;
    if (input1 > 0)
      n++;
    else
      break;
    int minT2 = smallest(input3, input2, &j);
    input1 = input2 - minT2 - abs(input4[j] - input4[i]);
    if (input1 > 0)
      n++;
    else
      break;
  }
  // Write code here
}

int _tmain(int argc, _TCHAR *argv[])
{

  Chef();
  return 0;
}
