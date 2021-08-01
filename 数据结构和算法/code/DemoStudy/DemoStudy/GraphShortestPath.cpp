#include "GraphShortestPath.h"

GraphShortestPath::GraphShortestPath()
{

}



void GraphShortestPath::Dijkstra(vector<vector<int>>& arr, int startIndex)
{
	int size = arr.size();
	vector<int> vcShortestPath(size, MAX_VALUE);
	vector<bool> vcVisited(size,false);
	vector<int> vcPathIndex(size,0);
	int min = 0;
	
	cout << "vertex:" << startIndex + 1 << endl;
	for (int i = 0; i < size - 1; i++)
	{
		vcVisited[startIndex] = true;
		for (int j = 0; j < size; j++)
		{
			int minPath = min + arr[startIndex][j];
			if (vcVisited[j] == false && minPath < vcShortestPath[j])
			{
				vcShortestPath[j] = minPath;
				vcPathIndex[j] = startIndex;
			}
		}


		min = MAX_VALUE;
		for (int a = 0; a < size; a++)
		{
			if (vcVisited[a] == false && min > vcShortestPath[a])
			{
				min = vcShortestPath[a];
				startIndex = a;
			}
		}

		cout << "edge:" << min << endl;
		cout << "vertex:" << startIndex + 1 << endl;
		
	}

	int a = 1;
}