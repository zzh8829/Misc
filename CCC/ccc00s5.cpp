#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

struct P
{
	P(double a = 0,double b=0):x(a),y(b){};
	double x,y;
}sp[1001];

bool out[1001];

double dis(const P& a,const P& b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
		cin >> sp[i].x >> sp[i].y;
	for(int i=0;i!=n;i++)//if(!out[i])
	{
		double l =    0;
		double r = 1000;
		for(int j=0;j!=n;j++)//if(!out[j] && i!=j)
		{
			if(sp[i].x==sp[j].x)
			{
				if(sp[i].y<sp[j].y)
				{
					out[j]=1;
				}
				if(sp[i].y>sp[j].y)
				{
					out[i]=1;
				}
			} else {
				P mid((sp[i].x+sp[j].x)/2,(sp[i].y+sp[j].y)/2);
				double interx = mid.x;
				if(sp[i].y!=sp[j].y)
				{
					double slope = -(sp[j].x-sp[i].x)/(sp[j].y-sp[i].y);	
					interx-=mid.y/slope;
				}
				if(sp[i].x<sp[j].x)
					r = min(interx,r);
				else
					l = max(interx,l);
			}
		}
		if(l>r) out[i]=1;
	}
	for(int i=0;i!=n;i++)if(!out[i])
		printf("The sheep at (%.2f, %.2f) might be eaten.\n", sp[i].x,sp[i].y);
	return 0;
}
	
