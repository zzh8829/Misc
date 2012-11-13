#include <iostream>
#include <cstdio>

using namespace std;

int r[7][7];

int way(int i)
{
	int w=1;
	if(r[i][0]==0)
		return w;
	for(int j=1;j<=r[i][0];j++)
		w*=(1+way(r[i][j]));
	return w;
}
	

int main()
{
	int n,in;
	cin >> n;
	for(int i=1;i!=n;i++)
	{
		cin >> in;
		r[in][ ++r[in][0] ] = i;
	}	
	cout << way(n) <<endl;
	system("pause");
	return 0;
}
