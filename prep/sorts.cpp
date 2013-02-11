#include<iostream>
using namespace std;


class Sorter
{
public:
void bubbleSort(int *arr,int size);
void selectionSort(int *arr,int size);
void insertionSort(int *arr,int size);
void shellSort(int *arr,int size);
void mergeSort(int *arr,int size);
void quickSort(int *arr,int size);
void display(int *arr,int size){ for(int i=0;i<size;i++) cout<<arr[i]<< " "; cout<<"\n";}
protected:

};

void Sorter::bubbleSort(int *arr,int size)
{
cout<<" BubbleSort:: ";
 bool  f  =  true;
 int i=0,j=0;
 for(;i<size && f == true;i++)
 {
  f = false;
  for(j=0;j<size-i-1;j++)
  {
    if(arr[j]>arr[j+1])
	{
	 f = true;
	 int tmp =  arr[j];
	 arr[j]=arr[j+1];
	 arr[j+1]=tmp;
	}
  }  
 }

}
void Sorter:: selectionSort(int *arr,int size)
{
cout<<" SelectionSort:: ";
for(int i=0;i<size;i++)
{
 for(int j=0;j<size;j++)
 {
  if(arr[i] < arr[j])
  {
   int tmp =  arr[i];
   arr[i] = arr[j];
   arr[j] = tmp;
  }
 }
}
}

void Sorter::insertionSort(int *arr,int size)
{
 cout<<"insertionSort:: ";
 for(int i=0;i<size;i++)
 { 
 int j = i+1 ;
 while(j > 0  && arr[j] < arr[j-1])
 {
 
   int tmp =  arr[j];
   arr[j]= arr[j-1];
   arr[j-1] =  tmp;  
   j--;
 }
 }
}

void Sorter::shellSort(int *arr,int size)
{
}

void Sorter::mergeSort(int *arr,int size)
{

}

void Sorter::quickSort(int *arr,int size)
{

}

int main(void)
{
 int arr[]={ 9,-9 , 1, 10, 3, -8 , 7 ,4};
 int size = sizeof(arr)/sizeof(int); 
 
 cout<<" Sorting Algos \n \t";
 Sorter s;
 s.display(arr,size); 
 
// s.bubbleSort(arr,size);
 //s.selectionSort(arr,size);
 s.insertionSort(arr,size);
 s.display(arr,size);
 
 return 0;
}
