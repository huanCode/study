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

void Sort::DemoBubbleSort()
{
	int length = 8;
	int arr[] = {6,1,3,2,10,9,14,4};
	SelectSort(arr, length);
}


void Sort::DemoSelectSort()
{
	int length = 8;
	int arr[] = { 6,1,3,2,10,9,14,4 };
	SelectSort(arr, length);
}


void Sort::Swap(vector<int>& lt, int indexA, int indexB)
{
	int tmp = lt[indexA];
	lt[indexA] = lt[indexB];
	lt[indexB] = tmp;

}

void Sort::Swap(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void Sort::BubbleSort(int arr[], int arrSize)
{
	cout << "ԭʼ���飺" << endl;
	int flag = arrSize;
	int length = arrSize;
	PrintArray(arr, arrSize);
	cout << "�������" << endl;
	while (flag > 0)
	{
		length = flag;
		flag = 0;
		
		for (int i = 1; i < length; i++)
		{
			
			if (arr[i - 1] > arr[i])
			{
				cout << "������� length = " << length << ",i = " << i << endl;
				Swap(arr[i - 1], arr[i]);
				PrintArray(arr,arrSize);
				flag = i;

			}

		}
		cout << "�������  -----" << endl;
	}

	int a = 1;
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

void Sort::PrintArray(int arr[], int size)
{
	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		cout << setw(3) << arr[i] << ",";
	}
	cout << "] " << endl;
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



void Sort::SelectSort(int arr[], int arrSize)
{
	cout << "ԭʼ���飺" << endl;
	PrintArray(arr, arrSize);
	cout << "������̣�" << endl;
	int minIndex = 0;
	//arrSize - 1 :��ʾֻҪѡ����С
	for (int i = 0; i < arrSize - 1; i++)
	{
		cout << "arrSize = " << arrSize  << ",��[ "<<i<<" ]��"<<endl;
		minIndex = i;
		for (int j = i + 1; j < arrSize; j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}

		}

		if (minIndex != i)
		{
			Swap(arr[minIndex], arr[i]);
			PrintArray(arr, arrSize);
		}

	}

	int a = 1;

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
	cout << "����������"<<endl;
	PrintVector(arr);
	int maxValue = arr[0];
	int minValue = arr[0];
	//��ȡ�����Сֵ
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
	cout << "��������:" << endl;
	PrintVector(count);

	
	for (int i = 1; i < arr.size(); i++)
	{
		count[i] = count[i] + count[i-1];
	}
	cout << "�ۼӼ�������:" << endl;
	PrintVector(count);

	vector<int> result(arr.size(),0);
	cout << "������̼������:" << endl;
	//for (int i = 0; i < arr.size(); i++)
	//{
	//	int indexCount = arr[i] - minValue;
	//	//count���¼����ĳ��������������ֵ�����Ǹ�ֵ�Ǵ�1��ʼ�ģ�
	//	//���Ҫ��ֵ��result���Ӧ�ü�һ
	//	int indexResult = --count[indexCount];
	//	result[indexResult] = arr[i];
	//	//count[indexCount]--;
	//	PrintVector(result);
	//}

	//���ַ��������,���ͬ��������ԭ�����е�˳��
	for (int i = arr.size() - 1; i >= 0 ;i--)
	{
		int indexCount = arr[i] - minValue;
		//count���¼����ĳ��������������ֵ�����Ǹ�ֵ�Ǵ�1��ʼ�ģ�
		//���Ҫ��ֵ��result���Ӧ�ü�һ
		int indexResult = --count[indexCount];
		result[indexResult] = arr[i];
		//count[indexCount]--;
		PrintVector(result);
	}

	cout << "����ý������:" << endl;
	PrintVector(result);

	int a = 1;
}
