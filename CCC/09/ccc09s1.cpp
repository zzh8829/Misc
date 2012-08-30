#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int a,b,cnt=0;
	cin >> a >> b;
	for(int i=int(pow(a,1.0/3.0)+0.5);i<=pow(b,1.0/3.0)+1;i++)
	{
		int t=i*i*i ;
		if((int)sqrt(t)*(int)sqrt(t)==t)
			cnt++;
	}
	cout << cnt <<endl;
	system("pause");
	return 0;
}
