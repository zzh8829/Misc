#include <iostream>
using namespace std;
int maxs[10010];
int main()
{

	int np,nr;
	cin >> np;
	int ps[52],rs[52];
	int in;
	for(int i=0;i!=np;i++)
	{
		cin >> in;
		ps[i] = in;
	}
	cin >> nr;
	for(int i=0;i!=nr;i++)
	{
		cin >> in;
		rs[i]  = in;
	}
	
	int max =0;
	for(int i=0;i!=nr;i++)
	for(int j=0;j!=np;j++)
	{
	int tmp = rs[i]/ps[j];
	
	if(tmp * ps[j] == rs[i])
	{
	if(tmp>=max)
	max = tmp;
	maxs[tmp]++;
	}
	}
	cout << maxs[max] << endl;
	return 0;
}
