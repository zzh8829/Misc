#include <iostream>
#include <string>

using namespace std;


int a[100005],b[100005],c[100005];


int main()
{
	string sa,sb;
	getline(cin ,sa );
	getline(cin ,sb );
	int na=0,nb=0;
	int fa=1,fb=1;
	for(int i=sa.size()-1;i!=-1;i--)
	{
		a[na++] = (char)sa[i] - 48;
	}
	for(int i=sb.size()-1;i!=-1;i--)
	{
		if(sb[i]=='-')
		{
			fb =-1;
			continue;
		}
		b[nb++] = (char)sb[i] - 48;
	}
	int ds = na;
	if(nb > na)
	ds = nb;
	for(int i=0;i!=ds;i++)
	{
		c[i] = a[i] + b[i];
	}
	for(int i=0;i!=ds;i++)
	{
		if(c[i] > 9 )
		{
			c[i+1]++;
			c[i] -= 10;
		}
	}
	if(c[ds])
	cout << c[ds] ;
	for(int i=ds-1;i!=-1;i--)
	{
		cout << c[i] ;
	}

	cout << endl;
	system("pause");
	return 0;
}

