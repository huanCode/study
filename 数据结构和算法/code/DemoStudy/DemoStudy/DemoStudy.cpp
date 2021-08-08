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
#include "tmp.h"
using namespace std;


int main()
{
	int length = 9;
	int arr[] = { 50,10,90,30,70,40,80,60,20 };
	//Select(arr, length);
	//Sort::Demo();
	//Sort::DemoBubbleSort();
	//Sort::DemoSelectSort();
	//QuickSort::Demo();
	//MergeSort::Demo();
	//HeapSort::Demo();
	//InsertSort::Demo();

	AvlTreeTmp::Demo();

	//Solution sl;
	//string s("AFDOBECODEBANC");
	//string t("ABC");
	//string result = sl.minWindow(s,t);

	vector<vector<int>> vc(5, vector<int>(5,0));
	vc[0][0] = 1;
	vc[0][1] = 4;
	vc[0][2] = 7;
	vc[0][3] = 11;
	vc[0][4] = 15;

	vc[1][0] = 2;
	vc[1][1] = 5;
	vc[1][2] = 8;
	vc[1][3] = 12;
	vc[1][4] = 19;

	vc[2][0] = 3;
	vc[2][1] = 6;
	vc[2][2] = 8;
	vc[2][3] = 16;
	vc[2][4] = 22;

	vc[3][0] = 10;
	vc[3][1] = 13;
	vc[3][2] = 14;
	vc[3][3] = 17;
	vc[3][4] = 24;

	vc[4][0] = 18;
	vc[4][1] = 21;
	vc[4][2] = 23;
	vc[4][3] = 26;
	vc[4][4] = 30;

	CQueue q;
	q.findNumberIn2DArray(vc,5);


}

