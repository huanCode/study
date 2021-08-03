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