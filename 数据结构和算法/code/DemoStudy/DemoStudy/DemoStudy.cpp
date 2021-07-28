// DemoStudy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "GraphMST.h"
using namespace std;

#define MAXINT 6
int c[MAXINT][MAXINT] = { {1000,6,1,5,1000,1000},{6,1000,5,1000,3,1000},{1,5,1000,5,6,4},{5,1000,5,1000,1000,2},{1000,3,6,1000,1000,6},{1000,1000,4,2,6,1000} };
void Prim(int n)
{
	int lowcost[MAXINT];//存储S中到达对应的其它各点的最小权值分别是多少
	int closest[MAXINT];//closest[]数组保存的是未在S中的点所到达S中包含的最近的点是哪一个,如:closest[i]=1表示i最靠近的S中的点是1
	bool s[MAXINT];//bool型变量的S数组表示i是否已经包括在S中
	int i, k;
	s[0] = true;//从第一个结点开始寻找,扩展
	for (i = 1; i <= n; i++)//简单初始化
	{
		lowcost[i] = c[0][i];
		closest[i] = 0;//现在所有的点对应的已经在S中的最近的点是1
		s[i] = false;
	}
	cout << "0->";
	for (i = 0; i < n; i++)
	{
		int min = 1000;//最小值,设大一点的值,后面用来记录lowcost数组中的最小值
		int j = 1;
		for (k = 1; k <= n; k++)//寻找lowcost中的最小值
		{
			if ((lowcost[k] < min) && (!s[k]))
			{
				min = lowcost[k]; j = k;
			}
		}
		cout << j << " " << "->";
		s[j] = true;//添加点j到集合S中
		for (k = 1; k <= n; k++)//因为新加入了j点,所以要查找新加入的j点到未在S中的点K中的权值是不是可以因此更小
		{
			if ((c[j][k] < lowcost[k]) && (!s[k]))
			{
				lowcost[k] = c[j][k]; closest[k] = j;
			}
		}
	}

	int a = 1;

}




int main()
{

	GraphMST g;
	g.InitArr_0();
	g.Prim(0);

	cout << "请输入初始权值数组:" << endl;
	for (int i = 0; i < MAXINT; i++)
	{
		for (int j = 0; j < MAXINT; j++)
		{
			//    cout<<"please enter c["<<i<<"]["<<j<<"]:";
			//    cin>>c[i][j];
			cout << c[i][j] << "\t";
			//    cout<<endl;
		}
		cout << endl;
	}

	Prim(MAXINT - 1);
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
