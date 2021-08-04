#include "common.h"

void PrintArray(int arr[], int size)
{
	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		if (size == i + 1)
		{
			cout << setw(3) << arr[i];
		}
		else
		{
			cout << setw(3) << arr[i] << ",";
		}
	}
	cout << "] " << endl;
}


void PrintArray(int arr[], int left, int right)
{
	cout << "[ ";
	while (left <= right)
	{
		if (left == right)
		{
			cout << setw(3) << arr[left];
		}
		else
		{
			cout << setw(3) << arr[left] << ",";
		}
		left++;
	}
	cout << "] " << endl;
}

void Swap(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}