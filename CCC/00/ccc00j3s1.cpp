#include <cstdio>
using namespace std;

int m ;
int cnt = 0;
int c1=0,c2=0,c3=0;
void f1()
{
	c1++;
	if(c1 == 35)
	{
		c1 = 0;
		m+=30;	
	}
}
void f2()
{
	c2++;
	if(c2 == 100)
	{
		c2 = 0;
		m+=60;
	}
}
void f3()
{
	c3++;
	if(c3 == 10)
	{
		c3 = 0;
		m+=9;
	}
}

int main()
{
	scanf("%d%d%d%d",&m,&c1,&c2,&c3);
	while(m>0)
	{
		m--;
		if(cnt%3==0)
		f1();
		else if(cnt%3==1)
		f2();
		else if(cnt%3==2)
		f3();
		cnt++;
	}
	printf("Martha plays %d times before going broke.",cnt);
	getchar();
	return 0;
}
