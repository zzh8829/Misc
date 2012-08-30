#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Box 
{
	int a;
	int b;
	int c;
	int p;
};

Box box[1010];

void swap(int& a,int &b,int &c)
{
	int t = 0;
	if ( a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	if ( a < c)
	{
		t = a;
		a = c;
		c = t;
	}
	if( b < c)
	{
		t = b;
		b = c;
		c = t;
	}
}

bool cmp(Box a, Box b)
{
	return a.p < b.p;
}

bool ok(int i,int a,int b,int c)
{
	swap(a,b,c);
	if(box[i].a < a || box[i].b < b || box[i].c < c)
	return false;
	return true;
}


int main()
{
	int bs,ns, a,b,c;
	cin >> bs;
	for(int i=0;i!=bs;i++)
	{
	cin >> a >> b >>c;
	swap(a,b,c);
	box[i].a =a;
	box[i].b =b;
	box[i].c =c;
	box[i].p = a*b*c;
	}
	sort(box,box+bs,cmp);
	cin >> ns;
	
	for(int i=0;i!=ns;i++)
	{
		int fit = 0 ,j=0;
		cin >> a >> b >>c;
		for(;j!=bs;j++)
		{
			if(box[j].p >= a*b*c)
			{
				if(ok(j,a,b,c))
				{
					fit = 1;
					break;
				}
			}
		}
		if(fit)	
		{
			cout << box[j].p <<endl;
		}
		else
		{
			cout << "Item does not fit." <<endl;
		}
	}	
	system("pause");
	return 0;
}
