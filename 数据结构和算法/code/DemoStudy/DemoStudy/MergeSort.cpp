#include "MergeSort.h"

void MergeSort::Demo()
{
	int length = 9;
	int arr[] = { 50,10,90,30,70,40,80,60,20 };
	cout << "原始数组:" << endl;
	PrintArray(arr, length);
	Sort(arr, length);
}

void MergeSort::Sort(int arr[], int arrLength)
{
	cout << "排序过程----" << endl;
	int* arrTemp = new int[arrLength];
	Sort(arr,0, arrLength - 1, arrTemp);
}

void MergeSort::Sort(int arr[], int left, int right, int arrTemp[])
{
	
	if (left < right)
	{
		int center = (left + right) / 2;
		cout << "Sort : left = " << left <<",center ="<< center << ",right = " << right << endl;
		Sort(arr,left,center, arrTemp);
		Sort(arr, center + 1, right, arrTemp);
		Merge(arr,left,center,right, arrTemp);

		cout << "排序后:" << endl;
		PrintArray(arr, left, right);
	}
}


void MergeSort::Merge(int arr[], int left, int center, int right, int arrTemp[])
{
	cout << "Merge : left = " << left << ",center =" << center << ",right = " << right << endl;
	int leftBegin = left;
	int leftEnd = center;
	int righeBegin = center + 1;
	int index = left;
	cout << "左边数组:" << endl;
	PrintArray(arr, left, leftEnd);
	cout << "右边数组:" << endl;
	PrintArray(arr, righeBegin, right);
	while (leftBegin <= leftEnd && righeBegin <= right)
	{
		if (arr[leftBegin] < arr[righeBegin])
		{
			arrTemp[index++] = arr[leftBegin++];
			cout << "left["<< leftBegin<<"] = "<< arr[leftBegin-1] << endl;

		}
		else
		{
			arrTemp[index++] = arr[righeBegin++];
			cout << "right[" << leftBegin << "] = " << arr[righeBegin - 1] << endl;

		}
	}

	while (leftBegin <= leftEnd)
	{
		arrTemp[index++] = arr[leftBegin++];
	}

	while (righeBegin <= right)
	{
		arrTemp[index++] = arr[righeBegin++];
	}

	while (left <= right)
	{
		arr[left] = arrTemp[left];
		left++;
	}


}