#include <iostream>
using namespace std;

int ok[8][8] = {
	{8,1,2,4,6,3,5,7},
	{4,3,5,7},
	{4,3,6,7},
	{2,7},
	{4,5,6,7},
	{2,7}};

int getMin(int a,int b)
{
	if(a>=b)
	return b;
	return a;
}

int  s[9],r[9],ans;

int main()
{
	for(int i=0;i!=8;i++)
	{
		int in;
		cin >> in;
		s[i] = in;
	}
	for(int i=0;i!=8;i++)
	{
		int in;
		cin >> in;
		r[i]= in;
	}
	for(int i=0;i!=8;i++)
	{	
		int no = getMin(s[i],r[i]);
		ans += no;
		s[i]-= no;
		r[i]-= no;
	}	
	for(int i=0;i!=6;i++)
	{
		for(int j=1;j!=ok[i][0];j++)
		{
			if(!s[i])
				break;
			int no = getMin(s[i],r[ok[i][j]]);
			ans += no;
			s[i] -=no;
			r[ok[i][j]] -=no;
		}
	}
	cout << ans <<endl;
	system("pause");
	return 0;
}
