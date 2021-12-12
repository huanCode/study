#include "InsertSort.h"


void InsertSort::Demo()
{
	vector<int> arr = { 50,10,90,30,70,40,80,60,20 };
	Sort(arr);
}

void InsertSort::Sort(vector<int>& arr)
{
	int value = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		value = arr[i];
		int j = 0;
		for (j = i-1; j >= 0; j--)
		{
			if (arr[j] > value)
			{
				arr[j + 1] = arr[j];
				continue;
			}
			break;

		}
		arr[j+1] = value;
	}
}