#include <iostream>
#include <string>
#include <cctype>
using namespace std;
char m[61],n,in,newc;
int main()
{
	string key;
	cin >> key;
	while(cin >> in)
	if(isupper(in))
	m[n++]=in;
	for(int i=0;i!=n;i++)
	{
		newc = m[i]+key[i%key.size()] - 'A';
		cout << char(newc<='Z'?newc:newc-26) ;
	}
	cout <<endl;
	return 0;
}
