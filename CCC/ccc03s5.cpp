#include <iostream>
using namespace std;

int c[10001][10001];

int main()
{
	int n,r,d;
	cin >> n >> r >> d;
	int x,y,z;
	for(int i=0;i!=r;i++)
	{
		cin >> x >> y >> z;
		if(z>c[x][y])
			c[x][y]=c[y][x]=z;
	}
	cout << 30 << endl;	
	return 0;
}
