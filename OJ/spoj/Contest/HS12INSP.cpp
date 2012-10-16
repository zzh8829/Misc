#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const float UDF = 9999;
int main()
{
	int cs;
	scanf("%d",&cs);
	while(cs--)
	{
		int a,b,r;
		int x1,y1,x2,y2;
		scanf("%d%d%d%d%d%d%d",&a,&b,&r,&x1,&y1,&x2,&y2);
		float k = x2!=x1?(y2-y1)/(float)(x2-x1):UDF;
		float c = k!=UDF?y1-k*x1:0;
		if(k==UDF)
		{
			float ansx = x1;
			float c2 = ansx*ansx-2*a*ansx+a*a+b*b-r*r;
			float b2 = -2*b;
			float delta = b2*b2-4*c2;
			float ansy = (-b+sqrt(delta))/2;
			if(ansy>=min(y1,y2)&& ansy<=max(y1,y2))
				printf("%.2f %.2f\n",ansx,ansy);
			else
				printf("%.2f %.2f\n",ansx,(-b-sqrt(delta))/2);
			continue;			
		}		
		float a2 = k*k+1;
		float b2 = 2*(c*k-a-b*k);
		float c2 = a*a+b*b+c*c-r*r-2*b*c;
		float delta = b2*b2-4*a2*c2;
		float ansx,ansx2;
		float ansy,ansy2;
		if(delta==0)
		{
			ansx = -b2/a2/2;
			ansy = k*ansx+c;
			printf("%.2f %.2f\n",ansx,ansy);
		}
		else
		{
			delta = sqrt(delta);
			ansx = (-b2+delta)/a2/2;
			ansx2 = (-b2-delta)/a2/2;
			ansy = k*ansx+c;
			ansy2 = k*ansx2+c;
			if(ansx>= min(x1,x2) && ansx <=max(x1,x2) &&
				ansy>=min(y1,y2) && ansy <= max(y1,y2))
				printf("%.2f %.2f\n",ansx,ansy);
			else
				printf("%.2f %.2f\n",ansx2,ansy2);		
		}
	}
	return 0;
}

