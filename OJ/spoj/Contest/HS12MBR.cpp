#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 1<<20;
int lbx,lby;
int rtx,rty;

void update(int x1,int y1,int x2,int y2)
{
	lbx = min(lbx,x1);
	lby = min(lby,y1);
	rtx = max(rtx,x2);
	rty = max(rty,y2);
}

int main()
{
	int cs;
	cin >> cs;
	while(cs--)
	{
		int n,mx,my,r;
		int x1,x2,y1,y2;
		char type;
		lbx=lby=INF;
		rtx=rty=-INF;
		
		cin >> n;
		for(int i=0;i!=n;i++)
		{
			cin >> type;
			switch(type)
			{
			case 'c':
				cin >> mx >> my >> r;
				update(mx-r,my-r,mx+r,my+r);
				break;
			case 'p':
				cin >> mx >> my;
				update(mx,my,mx,my);
				break;
			case 'l':
				cin >> x1 >> y1 >> x2 >> y2;
				update(min(x1,x2),min(y1,y2),max(x1,x2),max(y1,y2));
				break;
			}
		}
		printf("%d %d %d %d\n",lbx,lby,rtx,rty);
	}
	return 0;
}
				
