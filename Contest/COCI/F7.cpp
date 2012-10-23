#include <iostream>
#include <algorithm>
using namespace std;

int p[300001];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
		cin >> p[i];
	sort(p,p+n);
	int t=1;
	int maxp = 0;
	for(int i=n-1;i>=0;i--)
	{
		if(p[i]+t>=maxp)maxp=p[i]+t;
		else break;
		t++;
	}
	cout << t-1 << endl;
	return 0;
}
