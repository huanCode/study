#pragma once
#include <vector>
#include <iostream>
using namespace std;
class GraphMST
{
public:
	GraphMST();
	void InitArr_0();
	void InitArr_1();
	void Prim(int startIndex);

private:
	vector<vector<int>> m_arr;
};

