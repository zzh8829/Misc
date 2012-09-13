#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int dr[8]={0,1, -1,0, 0,-1, 1,0 };

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int com;
		int x,y,d,s;
		x=y=d=0;
		while(cin >> com && com!=0)
		{
			if(com==1)
			{	
				cin >> s;
				x+=s* dr[d*2];
				y+=s* dr[d*2+1];
			}
			if(com==2)
				d= (d+3)%4;
			if(com==3)
				d= (d+1)%4;
		}
		int dis = abs(x) + abs(y);
		cout << "Distance is "<< dis <<endl;
		if( !(x==0 && y==0))
		{
			if(x>=0 && y>=0)
			{
				if(d==0) cout << "3\n";
				if(d==0 || d==1)
				{
					if(x!=0)
					{
						printf("1\n%d\n",abs(x));
						x=0;
					}
					if(y!=0)
					printf("3\n");
				}	
				if(d==3) cout << "2\n";
				if(d==3 || d==2)
				{
					if(y!=0)
					{
						printf("1\n%d\n",abs(y));	
						y=0;
					}
					if(x!=0)
					printf("2\n");
				}	
			}
			else if(x<=0 && y>=0)
			{
				if(d==0) cout << "2\n";
				if(d==0 || d==3)
				{
					if(x!=0)
					{
						printf("1\n%d\n",abs(x));
						x=0;
					}
					if(y!=0)
					printf("2\n");
				}	
				if(d==1) cout << "3\n";
				if(d==1 || d==2)
				{
					if(y!=0)
					{
						printf("1\n%d\n",abs(y));	
						y=0;
					}
					if(x!=0)
					printf("3\n");
				}
			}
			else if(x<=0 && y<=0)
			{
				if(d==2) cout << "3\n";
				if(d==2 || d==3)
				{
					if(x!=0)
					{
						printf("1\n%d\n",abs(x));
						x=0;
					}
					if(y!=0)
					printf("3\n");
				}	
				if(d==1) cout << "2\n";
				if(d==1 || d==0)
				{
					if(y!=0)
					{
						printf("1\n%d\n",abs(y));	
						y=0;
					}
					if(x!=0)
					printf("2\n");
				}
			}
			else if(x>=0 && y<=0)
			{
				if(d==2) cout << "2\n";
				if(d==2 || d==1)
				{
					if(x!=0)
					{
						printf("1\n%d\n",abs(x));
						x=0;
					}
					if(y!=0)
					printf("2\n");
				}	
				if(d==3) cout << "3\n";
				if(d==3 || d==0)
				{
					if(y!=0)
					{
						printf("1\n%d\n",abs(y));	
						y=0;
					}
					if(x!=0)
					printf("3\n");
				}	
			}
			if( x==0 && y!=0)
				printf ("1\n%d\n",abs(y));				
			if( y==0 && x!=0)
				printf ("1\n%d\n",abs(x));
		}
		cout <<endl;		
	}
	system("pause");
	return 0;
}
