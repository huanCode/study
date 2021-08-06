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
}

