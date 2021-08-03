#pragma once
namespace Algos
{
	typedef enum _ORDER
	{
		ASC = 0,
		DSC
	}ORDER;

	typedef enum
	{
		SELECTION = 0,
		INSERTION,
		HEAP,
		QUICK,
		MERGE,
		BUBBLE
	}SORTTYPE;

	class Sort
	{
	public:
		Sort();
		~Sort();
	private:
		void selectionSort();
		void insertionSort();
		void heapSort();
		void quickSort();
		void mergeSort();
		void bubblesort();
	public:
		//template<typename T>
		void sort(int *, int len, ORDER o = ASC, SORTTYPE t = QUICK);
		int *mArr;
		int mLength;
	};
}

