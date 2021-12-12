#include "SelectSort.h"

void SelectSort::Demo()
{
	vector<int> arr = { 50,10,90,30,70,40,80,60,20 };
	Sort(arr);

}

void SelectSort::Sort(vector<int>& arr)
{
	int minIndex = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		minIndex = i;
		for (int j = i+1; j < arr.size(); j++)
		{
			minIndex = arr[j] < arr[minIndex] ? j : minIndex;
		}

		Swap(arr[minIndex],arr[i]);
	}
}