#include <iostream>
using namespace std;

typedef unsigned int uint;

class Sorter
{

public:
  void BubbleSort(int *arr, uint s);
  void SelectionSort(int *arr, uint s);
  void InsertionSort(int *arr, uint s);
  void QuickSort(int *arr, uint s);
  void HeapSort(int *arr, uint s);
  void ShellSort(int *arr, uint s);
  void MergeSort(int *arr, uint s);
  void Display(int *arr, uint s);
};

void Sorter::Display(int *arr, uint s)
{
  cout << "\n";
  for (uint i = 0; i < s; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void Sorter::BubbleSort(int *arr, uint s)
{
  cout << " \n BubbleSort...\n";
  for (uint i = 0; i < s; i++)
  {
    for (uint j = 0; j < s - i - 1; j++)
    {
      if (*(arr + j) > *(arr + j + 1))
      {
        int tmp = *(arr + j + 1);
        *(arr + j + 1) = *(arr + j);
        *(arr + j) = tmp;
      }
    }
  }
}

void Sorter::SelectionSort(int *arr, uint s)
{
  cout << "\n Selection Sorting..\n";
  for (uint i = 0; i < s; i++)
  {
    for (uint j = i; j < s; j++)
    {
      if (arr[i] < arr[j])
      {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

void Sorter::InsertionSort(int *arr, uint s)
{
  cout << " \n Insertion Sort....\n";
  for (uint i = 1; i < s; i++)
  {
    uint j = i;
    while (j > 0)
    {
      if (arr[j] < arr[j - 1])
      {
        int tmp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = tmp;
      }
      j--;
    }
  }
}

void Sorter::QuickSort(int *arr, uint s)
{
}

void Sorter::HeapSort(int *arr, uint s)
{
}

void Sorter::ShellSort(int *arr, uint s)
{
  // to be Implemented
}

void Sorter::MergeSort(int *arr, uint s)
{
}

int main(void)
{
  int arr[] = {5, -6, 1, 9, -10, 0};
  uint size = sizeof(arr) / sizeof(int);
  Sorter s;
  s.BubbleSort(arr, size);
  s.Display(arr, size);
  s.SelectionSort(arr, size);
  s.Display(arr, size);

  s.InsertionSort(arr, size);
  s.Display(arr, size);
  return 0;
}
