#include "common.h"
class Sort
{

public:
	Sort();


	static void Demo();
	static void DemoBubbleSort();
	static void DemoSelectSort();

	static void BubbleSort(int arr[],int arrSize);

	/*ѡ������*/
	static void SelectSort(int arr[],int arrSize);



	static void SelectSort(vector<int>& lt);

	/*ϣ������:�Ƕ�ֱ�Ӳ������������*/
	static void ShellSort(vector<int>& arr);

	static void CountSort(vector<int>& arr);


private:
	static void Swap(vector<int>& lt, int indexA, int indexB);
	static void Swap(int& a,int& b);
	static void PrintVector(vector<int>& arr);
	static void PrintArray(int arr[],int size);
};

