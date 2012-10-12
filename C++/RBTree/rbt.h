// RBTree.h: interface for the CRBTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RBTREE_H__9C701E48_A116_4AE0_8736_B5F45F530AF5__INCLUDED_)
#define AFX_RBTREE_H__9C701E48_A116_4AE0_8736_B5F45F530AF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define BLACK 0
#define RED   1
#define NULL  0
typedef int BOOL;

typedef struct RBTreeNode
{
	int key;
	int color;
	struct RBTreeNode *parent, *left, *right;
	RBTreeNode(){}
	RBTreeNode(int k):key(k){  // 创建新结点默认颜色为红色
		color = RED;
		parent = NULL;
		left = NULL;
		right = NULL;}
}RBTree, RBTreeNode;


class CRBTree  
{
public:
	CRBTree();
	virtual ~CRBTree();

	void RB_InitLeafNode();
	BOOL RB_Insert(int keyVal);
	BOOL RB_Delete(int keyVal);
	RBTreeNode *RB_Find(int keyVal);
	void RB_Print();
	int RB_GetSize()const { return m_Size; }
private:
	void RB_Insert_FixedUp(RBTreeNode *&pNode);
	void RB_Del_FixedUp(RBTreeNode *&pNode);
	void RB_Left_Rotate(RBTreeNode *&pNode);
	void RB_Right_Rotate(RBTreeNode *&pNode);
	void RB_Print(RBTreeNode *&pNode);
	void RB_SwapTwoNodes(RBTreeNode *&pNode1, RBTreeNode *&pNode2);
	void RB_EmptyTree(RBTreeNode *&pNode);
private:
	RBTree *m_root;  //根结点
	RBTreeNode *m_NIL; // 空结点
	int m_Size;
};

#endif // !defined(AFX_RBTREE_H__9C701E48_A116_4AE0_8736_B5F45F530AF5__INCLUDED_)

