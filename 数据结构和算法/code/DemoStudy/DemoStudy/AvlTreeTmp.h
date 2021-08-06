#include "common.h"
typedef struct AvlNodeTmp
{
	AvlNodeTmp(int dt, char c)
	{
		data = dt;
		height = 0;
		childLeft = 0;
		childRight = 0;
		this->c = c;
	}
	int 	data;
	char	c;
	int		height;
	AvlNodeTmp* childLeft;
	AvlNodeTmp* childRight;
	
}AvlNodeTmp,*PAvlNodeTmp;
class AvlTreeTmp
{
public:
	AvlTreeTmp();
	static void Demo();
	void PreOrderTraverse(AvlNodeTmp* pNode);


	bool Insert(int data,char c);
	/*bool isSymmetry(AvlNodeTmp* pNode);*/
	PAvlNodeTmp GetRoot();

	int GetDepth(AvlNodeTmp* pNode,int idepth);

	vector<string> TreePaths(AvlNodeTmp* pNode);
private:
	bool _insert(AvlNodeTmp*& pNode,int data,char c);
	int _getHeight(PAvlNodeTmp pNode);
	PAvlNodeTmp LL(PAvlNodeTmp pNode);
	PAvlNodeTmp LR(PAvlNodeTmp pNode);
	PAvlNodeTmp RR(PAvlNodeTmp pNode);
	PAvlNodeTmp RL(PAvlNodeTmp pNode);

	int _max(int a,int b){ return(((a) > (b)) ? (a) : (b));}
private:
	PAvlNodeTmp 	m_pRoot;
	vector<string>  m_vc;
	list<char>      m_list;


};

