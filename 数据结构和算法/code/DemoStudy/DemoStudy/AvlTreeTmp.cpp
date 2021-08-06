#include "AvlTreeTmp.h"

AvlTreeTmp::AvlTreeTmp()
:m_pRoot(0)
{

}

void AvlTreeTmp::Demo()
{
	AvlTreeTmp  at;
	at.Insert(5,'A');
	at.Insert(4, 'B');
	at.Insert(9, 'C');
	at.Insert(2, 'D');
	at.Insert(7, 'E');
	at.Insert(10, 'F');
	at.Insert(1, 'G');
	at.Insert(3, 'H');
	at.Insert(8, 'I');
	
	//at.PreOrderTraverse(at.GetRoot());
	int depth = at.GetDepth(at.GetRoot(),0);

	at.TreePaths(at.GetRoot());
}

PAvlNodeTmp AvlTreeTmp::GetRoot()
{
	return m_pRoot;
}

vector<string> AvlTreeTmp::TreePaths(AvlNodeTmp* pNode)
{

	if (pNode != 0)
	{
		PreOrderTraverse(pNode);
	}

	return m_vc;
}


void AvlTreeTmp::PreOrderTraverse(AvlNodeTmp* pNode)
{
	if (pNode == 0)
	{
		return;
	}
	cout << pNode->c << endl;
	m_list.push_back(pNode->c);
	if (pNode->childLeft == 0 && pNode->childRight == 0)
	{
		string str;
		for (list<char>::iterator i = m_list.begin(); i != m_list.end(); i++)
		{
			if (i != m_list.begin())
			{
				str += "->";
			}
			str += *i;
		}
		m_vc.push_back(str);
	}
	else
	{
		PreOrderTraverse(pNode->childLeft);
		PreOrderTraverse(pNode->childRight);
	}

	m_list.pop_back();


}


//bool AvlTreeTmp::isSymmetry(AvlNodeTmp* pNode )
//{
//	if (pNode == 0)
//		return false;
//
//	
//
//}


int AvlTreeTmp::GetDepth(AvlNodeTmp* pNode, int idepth)
{
	if (pNode == 0)
	{
		return idepth;
	}
	idepth++;
	int a = GetDepth(pNode->childLeft, idepth);
	int b = GetDepth(pNode->childRight, idepth);

	int max = 0;
	if (pNode->childLeft && pNode->childRight)
	{
		max = a > b ? b : a;
	}
	else
	{
		max = a > b ? a : b;
	}
	
}





bool AvlTreeTmp::Insert(int data,char c)
{
	return _insert(m_pRoot,data,c);
}

bool AvlTreeTmp::_insert(AvlNodeTmp*& pNode,int data, char c)
{
	bool ret = true;
	if (pNode == 0)
	{
		pNode = new AvlNodeTmp(data,c);
		if (pNode == 0)
		{
			ret = false;
		}
	}
	else if (data < pNode->data)
	{
		//左
		ret = _insert(pNode->childLeft,data,c);
		if (ret)
		{
			//int v = _getHeight(pNode->childLeft) - _getHeight(pNode->childRight);
			//if (v > 1)
			//{
			//	if ((pNode->childLeft->data) > data)
			//	{
			//		pNode = LL(pNode);
			//	}
			//	else
			//	{
			//		pNode = LR(pNode);
			//	}
			//}
		}
	}
	else if (data > pNode->data)
	{
		//右
		ret = _insert(pNode->childRight,data,c);
		if (ret)
		{
			//int v = _getHeight(pNode->childRight) - _getHeight(pNode->childLeft);
			//if (v > 1)
			//{
			//	if ((pNode->childRight->data) < data)
			//	{
			//		pNode = RR(pNode);
			//	}
			//	else
			//	{
			//		pNode = RL(pNode);
			//	}
			//}
		}
	}
	pNode->height = _max(_getHeight(pNode->childLeft), _getHeight(pNode->childRight));
	return ret;
}

PAvlNodeTmp AvlTreeTmp::LL(PAvlNodeTmp pNode)
{
	PAvlNodeTmp pNodeTmp = pNode->childLeft;
	pNode->childLeft = pNodeTmp->childRight;
	pNodeTmp->childRight = pNode;

	pNode->height = _max(_getHeight(pNode->childLeft), _getHeight(pNode->childRight));
	pNodeTmp->height = _max(_getHeight(pNodeTmp->childLeft), _getHeight(pNodeTmp->childRight));

	return pNodeTmp;
}

PAvlNodeTmp AvlTreeTmp::LR(PAvlNodeTmp pNode)
{
	pNode->childLeft = RR(pNode->childLeft);

	return LL(pNode);

}

PAvlNodeTmp AvlTreeTmp::RL(PAvlNodeTmp pNode)
{
	pNode->childRight = LL(pNode->childRight);
	return RR(pNode);
}


PAvlNodeTmp AvlTreeTmp::RR(PAvlNodeTmp pNode)
{
	PAvlNodeTmp pNodeChileRight = pNode->childRight;
	pNode->childRight = pNodeChileRight->childLeft;
	pNodeChileRight->childLeft = pNode;

	pNode->height = _max(_getHeight(pNode->childLeft), _getHeight(pNode->childRight));
	pNodeChileRight->height = _max(_getHeight(pNodeChileRight->childLeft), _getHeight(pNodeChileRight->childRight));
	return pNodeChileRight;
}

int AvlTreeTmp::_getHeight(PAvlNodeTmp pNode)
{
	int height = pNode == 0?0:(pNode->height + 1);
	return height;

}