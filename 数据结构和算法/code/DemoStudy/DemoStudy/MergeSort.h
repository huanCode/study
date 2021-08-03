#include "common.h"
/*πÈ≤¢≈≈–Ú*/
class MergeSort
{
public:
	static void Demo();
	static void Sort(int arr[],int arrLength);
	static void Sort(int arr[], int left,int right,int arrTemp[]);
	static void Merge(int arr[], int left,int center,int right, int arrTemp[]);
};

