#pragma once
class MyArrays
{
public:
	explicit MyArrays();
	explicit MyArrays(int arr[], int row, int col);
	~MyArrays();

	void display();

	bool isPatternThere(int[], int row, int col);
	void rotateRight(int arr[], int size, int k = 0);
	void rotateLeft(int arr[], int size, int k = 0);

	MyArrays &operator<<(int k);
	MyArrays &operator>>(int k);

private:
	int **mArr;
	int mRow, mCol;
};
