// headsort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "headsort.h"

int main()
{
	int dataArr[] = {16,4,10,14,7,9,3,2,8,1};

	HeapSort heap;
	heap.Sort(dataArr, 10);
    return 0;
}

