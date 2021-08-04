#include "SelectSort.h"

void SelectSort::Demo()
{

}

void SelectSort::Sort(int arr[], int length)
{
	int min = 0;
	int max = 0;
	int left = 0;
	int right = length - 1;

	cout << "ԭʼ����:" << endl;
	PrintArray(arr, length);
	cout << "����:" << endl;
	for (; left < right; left++, right--)
	{
		cout << "left = " << left << ",right = " << right << endl;
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
		//��Сֵ��right
		if (min == right)
		{
			min = max;
		}
		Swap(arr[min], arr[left]);
		PrintArray(arr, length);
	}
}
