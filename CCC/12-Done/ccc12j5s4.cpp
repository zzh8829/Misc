#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int n;
int finish;
bool check[7777780];

typedef vector< vector<int> > Pos;

struct Node
{
	Node(Pos p,int depth)
	{
		pos= p;
		d = depth;
	}
	Pos pos;
	int d;
};

int getBack(vector<int> vi)
{
	for(int i=n-1;i!=-1;i--)
		if(vi[i])
			return vi[i];
	return 0;
}

Pos makeNewPos(Pos pos, int a,int b)
{
	if(pos[b][0]==0)
	pos[b][0]=getBack(pos[a]);
	else
	{
		for(int i=n-1;i!=-1;i--)
		{
			if((pos[b])[i])
			{
				(pos[b])[i+1]=getBack(pos[a]);
				break;
			}
		}
	}
	for(int i=n-1;i!=-1;i--)
	{
		if(pos[a][i])
		{
			(pos[a])[i]=0;
			break;
		}
	}
	return pos;
}

int transPos(Pos pos)
{
	int tmp=0;
	for(int i=0;i!=n;i++)
	{
		if((pos[i])[0])
		for( int j=0;j!=n;j++)
		if((pos[i])[j])
		{
			tmp += (i+1) *( pow(10.0,n-(pos[i])[j])); 
		}
	}
	return tmp;
}

int search(Pos pos,int n)
{
	int ini = transPos(pos);
	if(n==1 || ini==finish)
	return 0 ;
	check[ini] = true ;
	int depth = 0;
	queue<Node> tree;
	tree.push(Node(pos,0));
	
	while(!tree.empty())
	{
		Node cNode = tree.front();
		tree.pop();
		Pos now = cNode.pos;
		for(int i=0;i!=n;i++)
		{
			// ->	
			if(i < n-1 )
			{
				if(now[i][0] != 0 &&( now[i+1][0] == 0 || getBack(now[i]) < getBack(now[i+1]) )) 
				{
					Pos newPos = makeNewPos(now,i,i+1);
					int tmp = transPos(newPos);
					if(!check[tmp])
					{
						if(tmp == finish)
						return cNode.d+1;	
						check[tmp]= true;	
						tree.push(Node(newPos,cNode.d+1) );
					}
				}
			}
			// <-
			if (i > 0)
			{
				if(now[i][0] != 0 && (now[i-1][0] == 0 || getBack(now[i]) < getBack(now[i-1])) )
				{
					
					Pos newPos = makeNewPos(now,i,i-1);
					int tmp = transPos(newPos);
					if(!check[tmp])
					{
						if(tmp == finish)
						return cNode.d+1;		
						check[tmp]= true;			
						tree.push( Node(newPos,cNode.d+1));
					}
				}
			}
			
		}
	}
	return -1;
}


int main()
{
	while(cin >> n && n!=0)
	{
		for(int i=0;i!=7777779;i++)
		check[i] = false;
		float ok = 0.1234567;
		finish = (pow(10.0,n))*ok;
		Pos pos;
		vector<int> init;
		for(int i=0;i!=n;i++)
			init.push_back(0);
		for(int i=0;i!=n;i++)
			pos.push_back(init);
		for(int i=0;i!=n;i++)
		{
			int in;
			cin >> in;
			(pos[i])[0] = in;
		}
		int ans = search(pos,n);
		if(ans==-1)
		cout << "IMPOSSIBLE" <<endl;
		else
		cout << ans <<endl;
	}
	system("pause");
	return 0;
}

