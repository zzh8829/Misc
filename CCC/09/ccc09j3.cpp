#include <iostream>
#include <cstdio>

using namespace std;

int o;
int f(int c)
{
	int t = o+c;
	if(t<0)
	t+=2400;
	else if(t>2359)
	t-=2400;
	if(t%100 > 59)
		t+=40;
	return t;
}

int main()
{
	int v,e,w,t,h,s;
	cin >> o;
	v= f(-300);
	e= f(-200);
	w= f(-100);
	t= f(0);
	h= f(100);
	s= f(130);
	printf("%d in Ottawa\n%d in Victoria\n%d in Edmonton\n%d in Winnipeg\n%d in Toronto\n%d in Halifax\n%d in St. John's\n",
		o,v,e,w,t,h,s);
	system("pause");
	return 0;
}
