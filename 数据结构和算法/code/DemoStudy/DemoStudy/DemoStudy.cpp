// DemoStudy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "GraphMST.h"
#include "GraphShortestPath.h"
#include "DataMatrix.h"
#include "Sort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "InsertSort.h"
#include "AvlTreeTmp.h"
#include "LeetCodeAllSample.h"
//#include "tmp.h"
using namespace std;

int uniquePaths(int m, int n) {
	vector<vector<int>> vc(m,vector<int>(n,0));
	for (int i = 0; i < vc.size(); i++)
	{
		vc[i][0] = 1;
	}

	for (int i = 0; i < vc[0].size(); i++)
	{
		vc[0][i] = 1;
	}

	int valueA = 0;
	int valueB = 0;
	for (int i = 1; i < vc.size(); i++)
	{
		for (int j = 1; j < vc[0].size(); j++)
		{
			valueA = vc[i - 1][j];
			valueB = vc[i][j - 1];
			vc[i][j] = valueA + valueB;
		}

	}

	return vc[m - 1][n - 1];
}



int main()
{
	uniquePaths(3,2);
	PacificAtlantic_M p;
	p.Demo();

}

