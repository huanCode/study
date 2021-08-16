#include "common.h"

void PrintArray(int arr[], int size)
{
	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		if (size == i + 1)
		{
			cout << setw(3) << arr[i];
		}
		else
		{
			cout << setw(3) << arr[i] << ",";
		}
	}
	cout << "] " << endl;
}


void PrintArray(int arr[], int left, int right, bool bline)
{
	cout << "[ ";
	while (left <= right)
	{
		if (left == right)
		{
			cout << setw(3) << arr[left];
		}
		else
		{
			cout << setw(3) << arr[left] << ",";
		}
		left++;
	}
	if (bline)
	{
		cout << "] " << endl;
	}
	else
	{
		cout << "] ";
	}
	
}


void PrintArray(vector<vector<int>>& matrix)
{
	if (matrix.size() == 0 || matrix[0].size())
	{
		return;
	}

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int  j = 0; j < matrix[0].size(); j++)
		{
			cout << setw(3)  <<matrix[i][j];
		}
		cout << endl;

	}

}





void Swap(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}