// headsort.cpp : 定义控制台应用程序的入口点。
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

