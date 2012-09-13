#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int o[256];
int n[3];
int main()
{
	o['A']=0;o['B']=1;o['C']=2;
	cin >> n[0] >> n[1] >>n[2];
	sort(n,n+3);
	char in;
	while(cin>>in)
	cout << n[o[in]] <<" ";	
	system("pause");
	return 0;
}
