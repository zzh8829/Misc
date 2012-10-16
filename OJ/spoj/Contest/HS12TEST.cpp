#include<iostream>
#include<algorithm>
using namespace std;
int n[5];
int main()
{
	cin >>n[0] >>n[1] >>n[2] >>n[3];
	sort(n,n+4);
	cout<<n[0] <<" " <<n[3] <<endl;
	return 0;
} 