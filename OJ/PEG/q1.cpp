#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

float s[11];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	cin >> s[i];
	sort(s,s+n);
	cout << "The median on the test is ";
	if(n&1)
	printf("%.1f\n",s[n/2]);
	else
	printf("%.1f\n",(s[n/2] + s[n/2-1])/2.0);
	system("pause");
	return 0;
}
