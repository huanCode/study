// CountSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CountSort.h"

int main()
{

	int date[] = {2,5,3,0,2,3,0,3};

	CountSort countObject;
	countObject.Sort(date, 8);

    return 0;
}

