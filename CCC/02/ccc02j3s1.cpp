#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int p,g,r,o,n,t=0,m=1000;
	cin >> p >> g >> r >> o >> n;
	for(int a = 0; a*p<=n;a++)
	for(int b = 0; b*g<=n;b++)
	for(int c = 0; c*r<=n;c++)
	for(int d = 0; d*o<=n;d++)
	if(a*p+b*g+c*r+d*o == n)
	{
		printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n ",a,b,c,d);
		t++;
		if(a+b+c+d < m)
		m = a+b+c+d;
	}
	printf("Total combinations is %d.\nMinimum number of tickets to print is %d.\n",t,m);
	system("pause");
	return 0;
}
