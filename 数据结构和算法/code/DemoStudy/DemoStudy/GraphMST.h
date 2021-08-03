#ifndef _SOURCEPARSERUNIT_H_ 
#define _SOURCEPARSERUNIT_H_
#include "common.h"
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

#endif