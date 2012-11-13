/*
ID: zzh8829
PROG: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
using namespace std;

int INFI = 1<<20;
int n,p,c;

struct E{
	int node;
	int weight;
	E(int n,int w):node(n),weidge(w){}
	bool operator ()(const E& l,const E& r) const
	{
		return l.weidge < r.weidge;
	}
};

vector<E> G[]

priority_queue<E,vector<E> > Q;

int main()
{
#ifndef LOCAL
	ifstream cin("butter.in");
	ofstream cout("butter.out");
#endif

	return 0;
}
