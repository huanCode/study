#include "QuickSort.h"

int QuickSort::length = 0;
void QuickSort::Demo()
{
	length = 9;
	int arr[] = { 50,10,90,30,70,40,80,60,20 };
	cout << "ԭʼ����:" << endl;
	PrintArray(arr, length);
	Sort(arr, length);
}

void QuickSort::Sort(int arr[], int arrLength)
{
	Sort(arr, 0, arrLength - 1);
}


void QuickSort::Sort(int arr[], int left, int right)
{
	int pivot = 0;
	if (left < right)
	{
		cout << "left = " << left << ",right = " << right << endl;
		pivot = Partition(arr, left, right);
		Sort(arr, left, pivot - 1);
		Sort(arr, pivot + 1, right);
	}
}

int QuickSort::Partition(int arr[], int left, int right)
{
	int middleValue = arr[left];
	cout << "middleValue = " << middleValue << endl;
	while (left < right)
	{
		while (left < right && arr[right] >= middleValue)
		{
			right--;
		}
		arr[left] = arr[right];
		cout << "�Ƚ� right = " << right << endl;
		PrintArray(arr, length);
		while (left < right && arr[left] <= middleValue)
		{
			left++;
		}

		arr[right] = arr[left];
		cout << "�Ƚ� left = " << left << endl;
		PrintArray(arr, length);
	}

	arr[left] = middleValue;
	cout << "�Ƚ����" <<endl;
	PrintArray(arr, length);
	cout << "---------------------------------------------" << endl<< endl;
	return left;
}
