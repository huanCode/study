// DemoStudy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "GraphMST.h"
#include "GraphShortestPath.h"
#include "DataMatrix.h"
#include "Sort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
using namespace std;

void Select(int arr[], int lenght)
{
	int min = 0;
	int max = 0;
	int left = 0;
	int right = lenght - 1;

	cout << "原始数组:" << endl;
	PrintArray(arr, lenght);
	cout << "排序:" << endl;
	for (; left < right; left++, right--)
	{
		cout << "left = "<<left<<",right = "<<right << endl;
		min = left;
		max = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (arr[i] > arr[max])
			{
				max = i;
			}

			if (arr[i] < arr[min])
			{
				min = i;
			}
		}
		cout << "min = " << min << ",max = " << max << endl;
		Swap(arr[max], arr[right]);
		//最小值在right
		if (min == right)
		{
			min = max;
		}
		Swap(arr[min], arr[left]);
		PrintArray(arr, lenght);
	}


}

int main()
{
	int length = 9;
	int arr[] = { 50,10,90,30,70,40,80,60,20 };
	Select(arr, length);
	//Sort::Demo();
	//Sort::DemoBubbleSort();
	//Sort::DemoSelectSort();
	//QuickSort::Demo();
	//MergeSort::Demo();
	HeapSort::Demo();
}

