#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

float p[1001];
int main()
{
	int n;
	string in;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> in>>p[i];
	}
	sort(p,p+n);
	float max= p[0]-p[n-1] + 360;
	for(int i=0;i!=n-1;i++)
	{
		float t = p[i+1]-p[i];	
		if(t>max) max =t;
	}
	cout << (int)((360-max)*12+0.999) <<endl;
	system("pause");
	return 0;
}
