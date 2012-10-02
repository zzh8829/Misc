/*
ID: zzh8829
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

const short N=1001;
int t[N];
struct Color
{
	short llx,lly,urx,ury,c;
}data[N];

int main()
{
#ifndef LOCAL
	ifstream cin("rect1.in");
	ofstream cout("rect1.out");
#endif
	int r,c,n;
	cin >> r >> c >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> data[i].llx >>  data[i].lly >> 
			 data[i].urx >>  data[i].ury >> 
			 	 data[i].c; 
	}
	for(int i=n-1;i>=0;i--)
	{
		int 
		for(int c=n-1;c>0;c--)
	}
	for(int i=1;i!=250;i++)
	{
		if(ncolor[i])
		{
			cout << i << " "<< ncolor[i] << endl;
		}
	}
	return 0;
}
