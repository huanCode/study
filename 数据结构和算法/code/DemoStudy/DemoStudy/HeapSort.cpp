#include "HeapSort.h"

void HeapSort::Demo()
{
	int length = 9;
	int arr[] = { 50,10,90,30,70,40,80,60,20 };
    cout << "原始数组:" << endl;
    PrintArray(arr, length);
	Sort(arr, length);
}

void HeapSort::Sort(int arr[], int length)
{
	for (int i = length / 2; i >= 0; i--)
	{
		Adjust(arr, i, length);
	}

	for (int i = length - 1; i >= 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;


		Adjust(arr, 0, i);
	}

	int a = 1;
}




void HeapSort::Adjust(int arr[], int index, int length)
{
	int childLeft = 0;
	int rightRight = 0;
	int maxIndex = index;

	while (1)
	{

		childLeft = index * 2 + 1;
		rightRight = index * 2 + 2;
		if (childLeft >= length)
		{
			break;
		}

		if (arr[maxIndex] < arr[childLeft])
		{
			maxIndex = childLeft;
		}

		if (rightRight < length && arr[maxIndex] < arr[rightRight])
		{
			maxIndex = rightRight;
		}

		if (maxIndex == index)
		{
			break;
		}

		int temp = arr[index];
		arr[index] = arr[maxIndex];
		arr[maxIndex] = temp;

		index = maxIndex;
	}

}
