#include "Sort.h"
Sort::Sort()
{

}


void Sort::Demo()
{
	vector<int> vc(10,0);
	vc[0] = 101;
	vc[1] = 109;
	vc[2] = 107;
	vc[3] = 103;
	vc[4] = 108;
	vc[5] = 102;
	vc[6] = 103;
	vc[7] = 110;
	vc[8] = 107;
	vc[9] = 103;

	Sort::CountSort(vc);
}


void Sort::Swap(vector<int>& lt, int indexA, int indexB)
{
	int tmp = lt[indexA];
	lt[indexA] = lt[indexB];
	lt[indexB] = tmp;

}

void Sort::PrintVector(vector<int>& arr)
{
	cout << "[ ";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << setw(3) << arr[i] <<  ",";
	}
	cout << "] "<<endl;
}


void Sort::SelectSort(vector<int>& lt)
{
	if (lt.size() == 0) 
	{
		return;
	}
	int min = 0;
	int length = lt.size() - 1;
	for (int i = 0;i < length;i++)
	{
		min = i;
		for (int j = i + 1; j < lt.size(); j++)
		{
			if (lt[min] > lt[j])
			{
				min = j;
			}

		}

		if (min != i)
		{
			Swap(lt, i, min);
		}
	}
}

void Sort::InsertSort(vector<int>& arr)
{
	int insertValue = 0;
	int j = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[(i-1)] > arr[i])
		{
			insertValue = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > insertValue; j--)
			{
				arr[(j+1)] = arr[j];
			}
			arr[(j+1)] = insertValue;
		}
	}

	int b = 0;
}


void Sort::ShellSort(vector<int>& arr)
{
	int increment = arr.size();
	int insertValue = 0;
	int j = 0;
	do
	{
		
		increment = increment / 2;
		for (int i = increment; i < arr.size(); i++)
		{
			if (arr[i] < arr[i-increment])
			{
				insertValue = arr[i];
				for (j = i - increment; j >= 0 && arr[j] > insertValue; )
				{
					arr[j + increment] = arr[j];
					j -= increment;
				}
				arr[j + increment] = insertValue;
			}
		}

	} while (increment > 0);

	int a = 1;
}



void Sort::CountSort(vector<int>& arr)
{
	cout << "待排序数组"<<endl;
	PrintVector(arr);
	int maxValue = arr[0];
	int minValue = arr[0];
	//获取最大、最小值
	for (int i = 1; i < arr.size() ;i++)
	{
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
		}

		if (arr[i] < minValue)
		{
			minValue = arr[i];
		}
	}
	cout << "------------------" << endl;
	int size = maxValue - minValue + 1;
	cout << "maxValue:" << maxValue << endl;
	cout << "minValue:" << minValue << endl;
	cout << "size    :" << size << endl;
	
	
	vector<int>  count(size,0);
	for (int i = 0; i < arr.size(); i++)
	{
		int value = arr[i] - minValue;
		count[value]++;
	}
	cout << "计数数组:" << endl;
	PrintVector(count);

	
	for (int i = 1; i < arr.size(); i++)
	{
		count[i] = count[i] + count[i-1];
	}
	cout << "累加计数数组:" << endl;
	PrintVector(count);

	vector<int> result(arr.size(),0);
	cout << "排序过程计算过程:" << endl;
	//for (int i = 0; i < arr.size(); i++)
	//{
	//	int indexCount = arr[i] - minValue;
	//	//count里记录的是某个数的排序索引值，但是该值是从1开始的，
	//	//如果要赋值给result里，则应该减一
	//	int indexResult = --count[indexCount];
	//	result[indexResult] = arr[i];
	//	//count[indexCount]--;
	//	PrintVector(result);
	//}

	//这种方法解决了,多个同个数组在原数组中的顺序
	for (int i = arr.size() - 1; i >= 0 ;i--)
	{
		int indexCount = arr[i] - minValue;
		//count里记录的是某个数的排序索引值，但是该值是从1开始的，
		//如果要赋值给result里，则应该减一
		int indexResult = --count[indexCount];
		result[indexResult] = arr[i];
		//count[indexCount]--;
		PrintVector(result);
	}

	cout << "排序好结果数组:" << endl;
	PrintVector(result);

	int a = 1;
}



