#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool ok(int i)
{
	stringstream ss;
	ss << i;
	string n;
	ss >> n;
	string n2 = n;
	for(int i=0;i!=n.size();i++)
	{
		char c = n[i];
		if(c == '2'||c=='3'||c =='4'||c=='5'||c=='7')
		return false;
		if(c=='6')
		c = '9';
		else if(c == '9')
		c = '6';
		n2[n.size()-i-1] = c;
	}
	if(n2 == n)
	return true;
	return false;
}

int main()
{
	int a,b;
	cin >> a >>b;
	int sum = 0;
	for(int i=a;i!=b+1;i++)
	{
		if(ok(i))
		sum++;
	}
	cout << sum <<endl;
	return 0;
}
