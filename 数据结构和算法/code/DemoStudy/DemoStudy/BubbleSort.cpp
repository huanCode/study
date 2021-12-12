#include "BubbleSort.h"


void BubbleSort::Demo()
{
	vector<int> arr = { 50,10,90,30,70,40,80,60,20 };
	Sort(arr);
}

void BubbleSort::Sort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = arr.size() -1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				Swap(arr[j],arr[j-1]);
			}

		}

	}
}