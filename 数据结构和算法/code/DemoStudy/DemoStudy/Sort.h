#include "common.h"
class Sort
{

public:
	Sort();


	static void Demo();
	static void DemoBubbleSort();

	static void BubbleSort(int arr[],int arrSize);

	/*选择排序*/
	static void SelectSort(vector<int>& lt);
	/*直接插入排序*/
	static void InsertSort(vector<int>& arr);
	/*希尔排序:是对直接插入排序的升级*/
	static void ShellSort(vector<int>& arr);

	static void CountSort(vector<int>& arr);
private:
	static void Swap(vector<int>& lt, int indexA, int indexB);
	static void Swap(int& a,int& b);
	static void PrintVector(vector<int>& arr);
	static void PrintArray(int arr[],int size);
};

