#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const float OB = M_PI/2;
inline float dis(int x1,int y1,int x2,int y2){
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
inline float Max(float a,float b){
	return a>b?a:b;
}
int p[21];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
		cin >> p[i*2] >> p[i*2+1];
	float max=0;
	for(int i=0;i!=n;i++)
	for(int j=0;j!=n;j++) if(j!=i)
	for(int k=0;k!=n;k++) if(k!=i && k!=j)
	{
		//cout << i << j << k <<endl;
		float a = dis( p[i*2],p[i*2+1],p[j*2],p[j*2+1] );
		float b = dis( p[j*2],p[j*2+1],p[k*2],p[k*2+1] );
		float c = dis( p[k*2],p[k*2+1],p[i*2],p[i*2+1] );
		float mA =  acos((b*b+c*c-a*a)/(2*b*c));
		float mB =	acos((c*c+a*a-b*b)/(2*c*a));
		float mC = 	acos((a*a+b*b-c*c)/(2*a*b));
		float d;
		if(mA >OB || mB > OB || mC > OB)
		d= Max(Max(a,b),c);
		else d = a/sin(mA);
		if(d>max) max = d;		
	}
	printf("%.2f\n",max);	
	system("pause");
	return 0;
}
