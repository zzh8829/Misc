#include <cstdio>

bool rsa(int n)
{
	int d=0;
	for(int i=1;i!=n+1;i++)
	{
		if(n%i==0)
		d++;
		if(d>4)
		return false;
	}
	if(d==4)
	return true;
	return false;
}
int main()
{
	int a,b;
	int cnt = 0;
	scanf("%d%d",&a,&b);
	for(int i=a;i!=b+1;i++)
	if(rsa(i))
	cnt++;
	printf("The number of RSA numbers between %d and %d is %d",a,b,cnt);
	return 0;
}