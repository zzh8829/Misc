#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	float g,c,t;
	scanf("%f%f%f",&g,&c,&t);
	float r = 2*c/g;
	float t1 = (sqrt(r*r + 4*r*t)-r)/2;
	float depth = (t-t1)*c;
	float v = t1*g;
	printf("%0.2f\n%0.2f\n",depth,v);
	return 0;
}
