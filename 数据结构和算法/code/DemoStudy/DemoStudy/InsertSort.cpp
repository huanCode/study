#include "InsertSort.h"


void InsertSort::Demo()
{
	int length = 9;
	int arr[] = { 50,10,90,30,70,40,80,60,20 };
	cout << "ԭʼ����:" << endl;
	PrintArray(arr, length);
	Sort(arr, length);
}

void InsertSort::Sort(int arr[], int length)
{
	int temp = 0;
	int j = 0;
	cout << "�������:" << endl;
	for (int i = 1; i < length; i++)
	{
		cout << "��������:";
		PrintArray(arr,0,i-1,false);
		cout << "  ��������:";
		PrintArray(arr, i, length - 1);
		if (arr[i] < arr[i-1])
		{
			temp = arr[i];
			
			for (j = i; j >= 0 && temp < arr[j-1]; j--)
			{

				arr[j] = arr[j - 1];

			}

			arr[j] = temp;
			cout << "  �ź���"<<endl;
			cout << "��������:";
			PrintArray(arr, 0, i,false);
			cout << "  ��������:";
			PrintArray(arr, i+1, length - 1);
			cout << "-------------------------------------" << endl;

		}


	}
}