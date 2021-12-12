#include "ShellSort.h"

void ShellSort::Demo()
{
	vector<int> arr = { 50,10,90,30,70,40,80,60,20 };
	Sort(arr);

}

void ShellSort::Sort(vector<int>& arr)
{
	int gap = arr.size() / 2;
	int value = 0;
	int j = 0;
	while (gap > 0)
	{
		//����Ƕ���ⲿ�ֺͲ�������һ����ֻ�Ƕ���gap������i++�Ǿ���
		for (int i = gap; i < arr.size(); i++)
		{
			value = arr[i];

			for (j = i - gap; j >=  0; j = j - gap)
			{
				if (arr[j] > value)
				{
					arr[j + gap] = arr[j];
					continue;
				}
				break;
			}
			arr[j + gap] = value;

		}
		gap = gap / 2;
	}
}
