#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void qsort(int *array, int beg, int end, int size)
{
	cout << "Inside of qsort!" << endl;	
	cout << "Size of array: " << sizeof(array)/sizeof(int) << endl;
	cout << "beg: " << beg << endl;
	cout << "end: " << end << endl;
	cout << "size: " << size << endl;
}

void msort(int *array, int beg, int end, int size)
{
	cout << "Inside of msort!" << endl;
	cout << "Size of array: " << sizeof(array)/sizeof(int) << endl;
	cout << "beg: " << beg << endl;
	cout << "end: " << end << endl;
	cout << "size: " << size << endl;
}
void sorter(int *array, int initial, int final, int size, void (*FuncPtr)(int*,int,int,int))
{
	FuncPtr(array, initial, final, size);
}

int main()
{
	void (*qsort_fp)(int*, int, int, int);
	qsort_fp = &qsort;
	void (*msort_fp)(int*, int, int, int);
	msort_fp = &msort;

	int array[5];
	for (int i = 0; i < sizeof(array)/sizeof(int); ++i)
	{
		array[i]=i;
	}

	int beg = array[0];
	int end = array[4];
	int size = 8;
	sorter(array, beg, end, size, qsort_fp);
	sorter(array, beg, end, size, msort_fp);

    return 0;
}