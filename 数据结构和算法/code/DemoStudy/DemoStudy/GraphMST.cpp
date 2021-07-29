#include "GraphMST.h"
#define MAX_VALUE	65536
GraphMST::GraphMST()
{

}
void GraphMST::InitArr_0()
{
	//有权无向图-0.png
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

void GraphMST::InitArr_1()
{
	//有权无向图-1.png
	int length = 9;
	vector<vector<int>> arr(length, vector<int>(length, MAX_VALUE));
	//			  1         2         3         4         5         6         7         8         9
	arr[0] = { MAX_VALUE,4		  ,MAX_VALUE,MAX_VALUE,MAX_VALUE,MAX_VALUE,MAX_VALUE,8        ,MAX_VALUE };
	arr[1] = { MAX_VALUE,MAX_VALUE,8        ,MAX_VALUE,MAX_VALUE,MAX_VALUE,MAX_VALUE,11       ,MAX_VALUE };
	arr[2] = { MAX_VALUE,8        ,MAX_VALUE,7        ,MAX_VALUE,4        ,MAX_VALUE,MAX_VALUE,2         };
	arr[3] = { MAX_VALUE,MAX_VALUE,7        ,MAX_VALUE,9        ,14       ,MAX_VALUE,MAX_VALUE,MAX_VALUE };
	arr[4] = { MAX_VALUE,MAX_VALUE,MAX_VALUE,9        ,MAX_VALUE,10       ,MAX_VALUE,MAX_VALUE,MAX_VALUE };
	arr[5] = { MAX_VALUE,MAX_VALUE,4        ,14       ,10       ,MAX_VALUE,2        ,MAX_VALUE,MAX_VALUE };
	arr[6] = { MAX_VALUE,MAX_VALUE,MAX_VALUE,MAX_VALUE,MAX_VALUE,2        ,MAX_VALUE,1        ,6         };
	arr[7] = { 8        ,11       ,MAX_VALUE,MAX_VALUE,MAX_VALUE,MAX_VALUE,1        ,MAX_VALUE,7		 };
	arr[8] = { MAX_VALUE,MAX_VALUE,2        ,MAX_VALUE,MAX_VALUE,MAX_VALUE,6        ,7        ,MAX_VALUE };
	m_arr = arr;
}

void GraphMST::Prim(int startIndex)
{
	vector<bool> visited(m_arr.size(),false);
	vector<int> closest(m_arr.size(), MAX_VALUE);
	int min = MAX_VALUE;

	visited[startIndex] = true;
	cout << "vertex:" << startIndex + 1 << endl;
	for (int i = 0; i < m_arr.size()-1; i++)
	{
		for (int j = 0; j < m_arr.size(); j++)
		{
			if (m_arr[startIndex][j] < closest[j] && visited[j] == false)
			{
				closest[j] = m_arr[startIndex][j];
			}
		}
		min = MAX_VALUE;
		for (int x = 0; x < m_arr.size(); x++)
		{
			if (visited[x] == false && closest[x] < min)
			{
				min = closest[x];
				startIndex = x;
			}

		}
		visited[startIndex] = true;
		cout << "edge:" << min << endl;
		cout << "vertex:" << startIndex + 1 << endl;
	}

}
