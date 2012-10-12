//////////////////////////////////
//////////////////////////
#include <iostream>
#include "rbt.h"
#include <Windows.h>
#include <ctime>
using namespace std;

void time_Test();
void Fun_Test();
int main()
{
	cout << "ºìºÚÊ÷RBTree²âÊÔ³ÌÐò !\n";
	Fun_Test();
	time_Test();
	return 0;
}

void Fun_Test()
{
	CRBTree tree;
	tree.RB_InitLeafNode();
 	tree.RB_Insert(10);
 	tree.RB_Insert(14);
 	tree.RB_Insert(4);
 	tree.RB_Insert(12);
	tree.RB_Insert(11);
	tree.RB_Insert(13);
 	tree.RB_Insert(7);
 	tree.RB_Insert(16);
 	tree.RB_Print();
 	tree.RB_Delete(14);
 	tree.RB_Delete(10);
 	Sleep(1000);
	tree.RB_Print();
}

void time_Test()
{
	CRBTree tree;
	clock_t t_insert, t_print, t_find;
	int nArrNodes[50000];
	tree.RB_InitLeafNode();
	srand((unsigned)time(NULL));
//	srand(0);
	t_insert = clock();
	for (int i = 0; i < 50000; i++)
	{
		nArrNodes[i] = rand()%10000000 +1;
		while (1)
		{
			if (tree.RB_Find(nArrNodes[i]) == NULL)
			{
				tree.RB_Insert(nArrNodes[i]);
				break;
			}
			else
				nArrNodes[i] = rand()%10000000 +1;
		}
	}
	t_insert = clock() - t_insert;
	t_print = clock();
	
	tree.RB_Print();
	t_print = clock() - t_print;
	t_find = clock();
	tree.RB_Find(32725);
	t_find = clock() - t_find;
	cout << "The tree nodes count is: " << tree.RB_GetSize() << endl;
	cout << "Insert data need time: " << t_insert << "ms." << endl;
	cout << "Print data need time: " << t_print << "ms." << endl;
	cout << "Find one data need time: " << t_find << "ms." << endl;
}

