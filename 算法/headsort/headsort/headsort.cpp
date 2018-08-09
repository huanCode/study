#include "stdafx.h"
#include "headsort.h"
#include <iostream>
using namespace std;

void HeapSort::Sort(int* dataArr, int size)
{
	if (dataArr == nullptr || size < 1)
	{
		return;
	}
	build_heap(dataArr, size);
	int heapSize = size;
	while (heapSize > 1)
	{
		
		swap(dataArr,1, heapSize);
		heapSize--;
		max_heap(dataArr,1, heapSize);
		show(dataArr, size);
		
	}

}

void HeapSort::build_heap(int* dataArr,int size)
{
	int curSize = size;
	while( (curSize/2) >= 1)
	{
		max_heap(dataArr,(curSize/2), size);
		curSize--;
		show(dataArr,size);
	}
}


void HeapSort::max_heap(int* dataArr,int curIndex, int size)
{

	int largest = curIndex;
	int left    = 0;
	int right   = 0;
	while(true)
	{
		left 	= get_left(curIndex);
		right 	= get_right(curIndex);

		if (right <= size && dataArr[curIndex - 1] < dataArr[right - 1])
		{
			largest = right;
		}

		if (left <= size && dataArr[largest - 1] < dataArr[left - 1])
		{
			largest = left;
		}

		if (largest != curIndex)
		{
			swap(dataArr,largest,curIndex);
			curIndex = largest;
		}
		else
		{
			return;
		}
	}
}

void HeapSort::swap(int* dataArr,int aIndex,int bIndex)
{

	int* dataA = dataArr + aIndex - 1;
	int* dataB = dataArr + bIndex - 1;

	int tmp = *dataA;

	*dataA = *dataB;
	*dataB = tmp;
}


void HeapSort::show(int* dataArr, int size)
{
	int curIndex = 0;
	while (curIndex < size)
	{
		cout << curIndex <<" == "<<dataArr[curIndex++]<< endl;
	}

	cout << "=======================" << endl;
	
}

int HeapSort::get_parent(int curIndex)
{
	return curIndex / 2;
}

int HeapSort::get_left(int curIndex)
{
	return curIndex * 2;
}

int HeapSort::get_right(int curIndex)
{
	return curIndex * 2 + 1;
}

