#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int x = 1,y=1;
int h[31]= {
	1,1,1,1,1,1,
	2,2,2,2,2,2,
	3,3,3,3,3,3,
	4,4,4,4,4,4,
	5,5,5,5,5,5};
int v[31]= {
	1,2,3,4,5,6,
	1,2,3,4,5,6,
	1,2,3,4,5,6,
	1,2,3,4,5,6,
	1,2,3,4,5,6};

int getPos(char c)
{
	if(isalpha(c))
	return c-'A';
	if(c==' ')
	return 26;
	if(c=='-')
	return 27;
	if(c=='.')
	return 28;
	if(c=='#')
	return 29;
}

int getNum(int n)
{
	int t = 0;
	t += abs(h[n] - x);
	t += abs(v[n] - y);
	x = h[n];
	y = v[n];
	return t;
}
int main()
{
	string line;
	getline(cin,line);
	int sum = 0;
	for(int i=0;i!=line.size();i++)
		sum+=getNum(getPos(line[i]));
	sum += getNum(getPos('#'));
	cout << sum <<endl;
	system("pause");
	return 0;
}
