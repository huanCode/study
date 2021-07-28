#include "Graph.h"



Graph::Graph()
{
	vector<vector<int>> arr(6, vector<int>(6, 0));
	arr[0][1] = 1;
	arr[0][2] = 1;
	arr[0][3] = 1;

	arr[1][0] = 1;
	arr[1][3] = 1;
	arr[1][4] = 1;

	arr[2][0] = 1;

	arr[3][0] = 1;
	arr[3][1] = 1;
	arr[3][4] = 1;
	arr[3][5] = 1;

	arr[4][1] = 1;
	arr[4][3] = 1;
	arr[4][5] = 1;

	arr[5][3] = 1;
	arr[5][4] = 1;

	Graph::DFS(arr, 0);
}

void Graph::DFS(vector<vector<int>>& arr,int startIndex)
{
	int i = startIndex;
	int j = 0;

	stack<int> mystack;
	mystack.push(startIndex);
	vector<bool> visit(arr.size(), false);
	visit[startIndex] = true;
	std::cout << startIndex << endl;

	while (true)
	{
		if (arr[i].size() > j)
		{
			if (arr[i][j] == 1 && !visit[j])
			{
				mystack.push(j);

				visit[j] = true;
				std::cout << j << endl;
				i = j;
				j = 0;
				continue;

			}
			else
			{
				j++;
			}
		}
		else
		{
			if (mystack.empty())
			{
				break;
			}
			mystack.pop();
			i = mystack.top();
			
			j = 0;
		}
	}



}