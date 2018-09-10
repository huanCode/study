#include "stdafx.h"
#include <memory.h>
#include "CountSort.h"

void CountSort::Sort(int* dataArr, int size)
{
	if (dataArr == 0 || size <1)
	{
		return;
	}

	//1、寻找数组最大值
	int maxNum = dataArr[0];
	for (int i = 1;i < size ;i++)
	{
		if (maxNum < dataArr[i])
		{
			maxNum = dataArr[i];
		}
	}

	//2.1、统计dataArr的值的个数
	maxNum+=2;
	int* countDataArr = new int[maxNum];
	memset(countDataArr, 0, maxNum * sizeof(int));

	int index = 0;
	for (int j = 0;j<size;j++)
	{
		
		index = dataArr[j]+1;
		//printf("1  countdataArr[%d] = %d \r\n", index, countDataArr[index]);
		countDataArr[index]++;
		//printf("2 countdataArr[%d] = %d \r\n", index, countDataArr[index]);
	}



	//for (int m = 0;m <maxNum;m++)
	//{
	//	printf("countdataArr[%d] = %d \r\n",m, countDataArr[m]);
	//}

	//2.2 统计小于dataArr的值的个数
	for (int k = 1; k <maxNum;k++)
	{
		countDataArr[k] = countDataArr[k] + countDataArr[k-1];
		printf("countdataArr[%d] = %d \r\n", k, countDataArr[k]);
	}



	//3 排序，花费n
	int* sortArr = new int[size];
	int tmpValue = 0;
	for (int y = size - 1;y >= 0 ;y--)
	{
		tmpValue = dataArr[y];
		index = countDataArr[tmpValue+1];
		countDataArr[tmpValue+1]--;
		sortArr[index-1] = tmpValue;
		//printf("sortArr[%d] = %d \r\n", index - 1, sortArr[index - 1]);
	}


	for (int m = 0; m < size; m++)
	{
		printf("sortArr[%d] = %d \r\n", m, sortArr[m]);
	}

	int a = 0;
	
}
