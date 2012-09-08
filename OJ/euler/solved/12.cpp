#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int fact(int n)
{
	if(n%210!=0) return 0;
	int cnt=0;
	for(int i=1;i<=sqrt(n);i++)
		if(n%i==0)
			cnt++;
	return cnt*2;
}

int main()
{
	int n=1,d=2;
	for(int i=1;i!=999999999;i++)
	{
		int c=fact(n);
	//	printf("%d_",n);
		if(c>=500)
		{
			printf("%d",n);
			break;
		}
		n+=d;
		d+=1;
	}
	getchar();
	return 0;
}
