#include "GraphMST.h"
#define MAX_VALUE	65536
GraphMST::GraphMST()
{

}
void GraphMST::InitArr_0()
{
	int length = 6;
	vector<vector<int>> arr(length, vector<int>(length, MAX_VALUE));
	arr[0] = { MAX_VALUE,6,1,5,MAX_VALUE,MAX_VALUE };
	arr[1] = { 6,MAX_VALUE,5,MAX_VALUE,3,MAX_VALUE };
	arr[2] = { 1,5,MAX_VALUE,5,6,4 };
	arr[3] = { 5,MAX_VALUE,5,MAX_VALUE,MAX_VALUE,2 };
	arr[4] = { MAX_VALUE,3,6,MAX_VALUE,MAX_VALUE,6 };
	arr[5] = { MAX_VALUE,MAX_VALUE,4,2,6,MAX_VALUE };

	m_arr = arr;
}

void GraphMST::Prim(int startIndex)
{
	vector<bool> visited(m_arr.size(),false);
	vector<int> closest(m_arr.size(), MAX_VALUE);
	int min = MAX_VALUE;

	for (int i = 0; i < m_arr.size(); i++)
	{
		cout << startIndex<<endl;
		for (int j = 0; j < m_arr.size(); j++)
		{
			if (m_arr[startIndex][j] < min && visited[j] == false)
			{
				closest[j] = m_arr[startIndex][j];
			}
		}

		for (int x = 0; x < m_arr.size(); x++)
		{
			if (visited[x] == false && closest[x] < min)
			{
				min = closest[x];
				startIndex = x;
			}

		}
	}

}
