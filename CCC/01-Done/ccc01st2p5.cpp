#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

float Per = 40;
float Den = (10*Per+1)*(10*Per+1)/100.0;

struct Dot
{
	int x;
	int y;
};
struct DotF
{
	DotF(float a,float b){ x=a;y=b; }
	float x;
	float y;
};
inline float getDis(const DotF& a,const Dot& b)
{
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}
Dot r[51];
int p[51];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> r[i].x >> r[i].y ;
	}
	//cin >> n;
	for(float i=0;i<=10;i+=1.0/Per)
	for(float j=0;j<=10;j+=1.0/Per)
	{
		int mn;
		float min = 101.0;
		for(int k=0;k!=n;k++)
		{
			float dis = getDis(DotF(i,j),r[k]);
			if( dis < min )
			{
				min = dis;
				mn = k;
			}
		}
		p[mn]++;
	} 
	for(int i=0;i!=n;i++)
	{
		printf("Restaurant at (%d,%d) serves %.0f%% of the population.\n",r[i].x,r[i].y,p[i]/Den);
	}
	system("pause");
	return 0;
}
