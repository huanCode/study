#include "common.h"
class Sort
{

public:
	Sort();


	static void Demo();
	/*ѡ������*/
	static void SelectSort(vector<int>& lt);
	/*ֱ�Ӳ�������*/
	static void InsertSort(vector<int>& arr);
	/*ϣ������:�Ƕ�ֱ�Ӳ������������*/
	static void ShellSort(vector<int>& arr);

	static void CountSort(vector<int>& arr);
private:
	static void Swap(vector<int>& lt, int indexA, int indexB);

	static void PrintVector(vector<int>& arr);

};

