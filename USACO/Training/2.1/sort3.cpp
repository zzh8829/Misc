/*
ID: zzh8829
PROG: sort3
LANG: C++
*/
//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("sort3.in");
ofstream cout("sort3.out");

int c[4],m[1001],cnt,n;

int main()
{
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> m[i];	
		c[m[i]]++;
	}
	int p2=c[1],p3=n-1;
	for(int i=0;i!=c[1];i++)
	{
		if(m[i]==2)for(;p2<n;p2++)if(m[p2]==1)
		{
			m[i] =1,m[p2] =2,cnt++;
			break;
		}
		if(m[i]==3)for(;p3>c[1];p3--)if(m[p3]==1)
		{
			m[i] = 1,m[p3] = 3,cnt++;
			break;
		}
	}
	p3 = n-1;
	for(int i=c[1];i!=c[1]+c[2];i++)
	{
		if(m[i]==3)for(;p3>=c[1]+c[2];p3--)if(m[p3]==2)
		{
			m[i] = 2;m[p3] = 3;cnt++;
			break;
		}
	}
	cout <<cnt <<endl;
//	system("pause");
	return 0;
}
