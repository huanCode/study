#pragma once
#include <vector>
using namespace std;
class GraphMST
{
public:
	GraphMST();

	void Prim(vector<vector<int>>& arr,int startIndex);
};

