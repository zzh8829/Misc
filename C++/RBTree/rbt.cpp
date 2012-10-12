// RBTree.cpp: implementation of the CRBTree class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include "rbt.h"
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// 构造函数
CRBTree::CRBTree()
{
	m_root = m_NIL = NULL;
	m_Size = 0;
}

// 析构函数
CRBTree::~CRBTree()
{
	RB_EmptyTree(m_root);
	delete m_NIL;
	m_root = m_NIL = NULL;
	cout << "Empty the tree!\n";
}

// 初始化叶子结点
void CRBTree::RB_InitLeafNode()
{
	m_root = new RBTree(-1);
	m_NIL = new RBTreeNode(-1);
	m_NIL->color = BLACK;  // 叶子结点颜色都为黑色
	m_NIL->parent = NULL;
	m_NIL->left = m_NIL->right = NULL;
	m_root = m_NIL;
	m_root->parent = m_NIL;
}

// 插入树结点
BOOL CRBTree::RB_Insert( int keyVal )
{
	RBTreeNode *pNewNode = new RBTreeNode(keyVal);
	pNewNode->left = m_NIL;
	pNewNode->right = m_NIL;
	RBTreeNode *pNode = m_root;
	RBTreeNode *pPreNode = m_NIL;
	while(pNode != m_NIL)  // 树不为空
	{
		pPreNode = pNode;
		if (keyVal < pNode->key)
		{
			pNode = pNode->left;
		}
		else if (keyVal > pNode->key)
		{
			pNode = pNode->right;
		}
		else{
			delete pNewNode;
			return 0;
		}
	}
	pNewNode->parent = pPreNode;
	if (pPreNode == m_NIL)  // 树为空
	{
		pNewNode->color = BLACK;
		m_root = pNewNode;
	}
	else
	{
		if (keyVal < pPreNode->key)
		{
			pPreNode->left = pNewNode;
		}
		else
			pPreNode->right = pNewNode;
	}
	m_Size++;
//	cout << "Insert "<< m_Size << " node: " << keyVal << " succeeded!\n";
	RB_Insert_FixedUp(pNewNode);
	return 1;
}

// 删除树结点
BOOL CRBTree::RB_Delete( int keyVal )
{
	RBTreeNode *pDelNode, *pPreNode = m_NIL;
	if (m_root == m_NIL)
	{
		return 0;
	}
// 	pDelNode = m_root;
// 	while(pDelNode != m_NIL)
// 	{
// 		if (keyVal < pDelNode->key)
// 		{
// 			pPreNode = pDelNode;
// 			pDelNode = pDelNode->left;
// 		}
// 		else if (keyVal > pDelNode->key)
// 		{
// 			pPreNode = pDelNode;
// 			pDelNode = pDelNode->right;
// 		}
// 		else
// 			break;
// 	}
	pDelNode = RB_Find(keyVal);
	if (pDelNode == NULL)
	{
		return 0; // 没有此结点
	}
	pPreNode = pDelNode->parent;
	//从该结点的左子树找出最大的结点或从右子树找出最小的结点， 两者的值进行替换
	RBTreeNode *pTemp;
	RBTreeNode *pDelChild;
	if (pDelNode->left != m_NIL && pDelNode->right != m_NIL)
	{ // 有两个子结点，查找左子树
		pTemp = pDelNode->left;
		while(pTemp->right != m_NIL)
		{
			pTemp = pTemp->right;
		}

		RB_SwapTwoNodes(pTemp, pDelNode);
	
		pDelChild = pTemp->left;
		pDelChild->parent = pTemp->parent;
		if (pTemp->parent->left == pTemp)
		{
			pTemp->parent->left = pDelChild;
		}
		else
			pTemp->parent->right = pDelChild;
	}
	else if (pDelNode->left == m_NIL && pDelNode->right == m_NIL)
	{ // 要删除的结点是叶子结点
		if (pPreNode == m_NIL)
		{
			delete m_root;
			m_root = m_NIL;
			m_Size--;
			return 1;
		}
		else
		{
			if (pDelNode == pDelNode->parent->left)
			{
				pPreNode->left = m_NIL;
			}
			else
				pPreNode->right = m_NIL;
			pDelChild = m_NIL;
			pDelChild->parent = pDelNode->parent;
			pTemp = pDelNode;
		}
	}
	else // 有一个子结点
	{ 
		if (pDelNode->left != m_NIL)
		{
			pDelChild = pDelNode->left;
		}
		else 
		{
			pDelChild = pDelNode->right;
		}
		if (pDelChild == pPreNode->left)
		{
			pDelChild->parent = pPreNode;
			pPreNode->left = pDelChild;
		}
		else
		{
			pDelChild->parent = pPreNode;
			pPreNode->right = pDelChild;
		}
		pTemp = pDelNode;	
	}
	if (pTemp->color == BLACK)
	{
		RB_Del_FixedUp(pDelChild);
	}
//	cout << "Deleted node: " << pTemp->key << endl;
	delete pTemp;
	m_Size--;
	return 1;
}

// 查找指定结点，成功 放回该结点，否则返回NULL
RBTreeNode * CRBTree::RB_Find( int keyVal )
{
	RBTreeNode *pNode;
	if (m_root == m_NIL)
	{
		return NULL;
	}
	pNode = m_root;
	while(pNode != m_NIL)
	{
		if (keyVal < pNode->key)
		{
			pNode = pNode->left;
		}
		else if (keyVal > pNode->key)
		{
			pNode = pNode->right;
		}
		else{
//			cout << "Find node: " << keyVal << "succeeded!\n";
			return pNode;
		}
	}
	return NULL;
}

// 插入结点后形成的新结构不满足红黑树性质和对其进行处理
void CRBTree::RB_Insert_FixedUp( RBTreeNode *&pNode )
{
	while (pNode->parent->color == RED)
	{
		RBTreeNode *pNodeParent = pNode->parent;
		RBTreeNode *pNodePaBro;
		if (pNodeParent->parent->left == pNodeParent) 
			pNodePaBro = pNodeParent->parent->right;
		else
			pNodePaBro = pNodeParent->parent->left;
		if (pNodePaBro->color == RED)
		{  // 父结点和叔结点都是红色 ==>> 父--黑  叔--黑  祖父--红
			pNodeParent->color = BLACK;
			pNodePaBro->color = BLACK;
			pNodeParent->parent->color = RED;
			pNode = pNode->parent->parent;
			if (pNode == m_NIL)
			{
				m_root->color = BLACK;
				return ;
			}
		}
		/// 红父 黑叔结点 或者没有叔结点
		else if(pNodeParent->parent->left == pNodeParent && pNodeParent->left == pNode)
		{
			pNodeParent->color = BLACK;
			pNodeParent->parent->color = RED;
			RB_Right_Rotate(pNode->parent->parent);
			break;
		}
		else if (pNodeParent->parent->left == pNodeParent && pNodeParent->right == pNode)
		{
			pNode = pNode->parent;
			RB_Left_Rotate(pNode);
		}
		else if (pNodeParent->parent->right == pNodeParent && pNodeParent->left == pNode)
		{
			pNode = pNode->parent;
			RB_Right_Rotate(pNode);
		}
		else 
		{
			pNodeParent->color = BLACK;
			pNodeParent->parent->color = RED;
			RB_Left_Rotate(pNode->parent->parent);
			break;
		}
	}// while
	m_root->color = BLACK;
}

// 删除结点后形成的新结构不满足红黑树性质和对其进行处理
void CRBTree::RB_Del_FixedUp( RBTreeNode *&pNode )
{
	int nLRFlag;
	RBTreeNode *pBroNode;
	while(pNode != m_root && pNode->color == BLACK)
	{
		if (pNode->parent->left == pNode)
		{
			nLRFlag = 0;
			pBroNode = pNode->parent->right;
		}
		else 
		{
			nLRFlag = 1;
			pBroNode = pNode->parent->left;
		}
		
		//1 父-red  无兄 子-red  ==>> 子-black
		//2 父-black  兄-red  ==>> 父-red 兄-black 旋转父结点 
		if (pBroNode->color == RED)
		{
			pNode->parent->color = BLACK;
			pBroNode->color = BLACK;
			if (nLRFlag == 0)
			{
				RB_Left_Rotate(pNode->parent);
			}
			else
				RB_Right_Rotate(pNode->parent);
		}
		//3 兄-black  两黑侄  ==>>	兄=红 子=黑 红父=黑 往上遍历(黑父)
		else if (pBroNode->left->color == BLACK && pBroNode->right->color == BLACK)
		{
			pNode->color = BLACK;
			pBroNode->color = RED;
			pNode->parent->color = BLACK;
			pNode = pNode->parent;  // 往上遍历
		}
		//4 兄-black  左黑侄右红侄  ==>> 兄=父色 父=黑 侄=黑 (子=黑) 左旋转父节点
		else if (pBroNode->left->color == BLACK && pBroNode->right->color == RED)
		{
			if (nLRFlag == 0)
			{
				pBroNode->color = pNode->parent->color;
				pNode->parent->color = BLACK;
				pNode->color = BLACK;
				pBroNode->right->color = BLACK;				
				RB_Left_Rotate(pNode->parent);
				break;
			}
			else 
			{
				RBTreeNode *pPa = pNode->parent;
				pBroNode->left->color = pNode->parent->color;
				pNode->parent->color = BLACK;
				RB_Left_Rotate(pBroNode);
				RB_Right_Rotate(pPa);
				break;
			}	
		}
		//5	兄-black  左红侄右黑侄  ==>> 侄=父色 父=黑 右旋转兄 左旋转父
		else if (pBroNode->left->color == RED && pBroNode->right->color == BLACK)
		{
			
			if (nLRFlag == 0)
			{
				RBTreeNode *pPa = pNode->parent;
				pBroNode->left->color = pNode->parent->color;
				pNode->parent->color = BLACK;
				RB_Right_Rotate(pBroNode);
				RB_Left_Rotate(pPa);
				break;
			}
			else 
			{
				pBroNode->color = pNode->parent->color;
				pNode->parent->color = BLACK;
				pNode->color = BLACK;
				pBroNode->right->color = BLACK;				
				RB_Right_Rotate(pNode->parent);
				break;
			}	
		}
		else  //两红侄的情况 转换成一黑一红的情况
		{
			if (nLRFlag == 0)
			{
				pBroNode->left->color = BLACK;
			}
			else
			{
				pBroNode->right->color = BLACK;
			}	
		}
	}
	pNode->color = BLACK;  //子 ==> black
	return;
}

// 左旋处理
void CRBTree::RB_Left_Rotate( RBTreeNode *&pNode )
{
	RBTreeNode *pNodeA = pNode->parent;
	RBTreeNode *pNodeB = pNode->right;
	pNode->right = pNodeB->left;
	pNodeB->left->parent = pNode;
	pNodeB->left = pNode;
	pNode->parent = pNodeB;

	if (pNode == pNodeA->left)
	{  // 父子不同边
		pNodeA->left = pNodeB;
		pNodeB->parent = pNodeA;
	}
	else if (pNode = pNodeA->right)
	{
		pNodeA->right = pNodeB;
		pNodeB->parent = pNodeA;
	}
	else // m_root == m_NIL
	{
		if (pNodeA == m_NIL)
		{  // pNode 原本为根结点
			pNodeB->parent = m_NIL;
			m_root = pNodeB;
		}
	}
//	cout << "RB_Left_Rotate()\n";
}

// 右旋处理函数
void CRBTree::RB_Right_Rotate( RBTreeNode *&pNode )
{
	RBTreeNode *pNodeA = pNode->parent;
	RBTreeNode *pNodeB = pNode->left;
	pNode->left = pNodeB->right;
	pNodeB->right->parent = pNode;
	pNodeB->right = pNode;
	pNode->parent = pNodeB;
	
	if (pNode == pNodeA->right)
	{  // 父子不同边
		pNodeA->right = pNodeB;
		pNodeB->parent = pNodeA;
	}
	else if (pNode = pNodeA->left)
	{
		pNodeA->left = pNodeB;
		pNodeB->parent = pNodeA;
	}
	else // m_root == m_NIL
	{
		if (pNodeA == m_NIL)
		{  // pNodeA 原本为父结点
			pNodeB->parent = m_NIL;
			m_root = pNodeB;
		}
	}
//	cout << "RB_Right_Rotate()\n";
}

void CRBTree::RB_Print()
{
	if (m_root == m_NIL)
	{
//		cout << "树为空！\n";
		return ;
	}
	RB_Print(m_root);
	cout << endl;
}

void CRBTree::RB_Print( RBTreeNode *&pNode )
{
	if (pNode != m_NIL)
	{
		cout << pNode->key << "(" << pNode->color << ")  ";
		RB_Print(pNode->left);
		RB_Print(pNode->right);
	}
}

void CRBTree::RB_SwapTwoNodes( RBTreeNode *&pNode1, RBTreeNode *&pNode2 )
{
	int t = pNode1->key;
	pNode1->key = pNode2->key;
	pNode2->key = t;
}

void CRBTree::RB_EmptyTree( RBTreeNode *&pNode )
{
	if (pNode != m_NIL)
	{
		RB_EmptyTree(pNode->left);
		RB_EmptyTree(pNode->right);
		delete pNode;
	}
}

