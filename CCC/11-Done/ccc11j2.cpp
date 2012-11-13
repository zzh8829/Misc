#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int h,m;
	cin >> h >> m;
	bool t = false;
	int i=1;
	for(;i<=m;i++)
	{
		if((-6*i*i*i*i + h*i*i*i + 2*i*i + i) <= 0)
		{
			t=true;
			break;
		}
	}
	if(t)
	printf("The balloon first touches ground at hour:\n%d\n",i);	
	else
	printf("The balloon does not touch ground in the given time.\n");	
	system("pause");
	return 0;
}
