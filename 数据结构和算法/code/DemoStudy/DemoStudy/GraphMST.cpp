#include "GraphMST.h"
#define MAX_VALUE	65536
GraphMST::GraphMST()
{

}


void GraphMST::Prim(vector<vector<int>>& arr, int startIndex)
{
	//vector<bool> visited(arr.size(),false);
	vector<int> closest(arr.size(), MAX_VALUE);
	int min = MAX_VALUE;

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[startIndex][j] != 0 && arr[startIndex][j] < min)
			{
				closest[j] = arr[startIndex][j];
			}
		}

	}

}
