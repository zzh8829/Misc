#include <iostream>
using namespace std;

int a,b;
bool l[27][27]={0};
int c[27][27];

int main()
{
	cin >> a>> b;
	int cats;
	cin >> cats;
	int ca,cb;
	for(int i=0;i!=cats;i++)
	{
		cin>>ca>>cb;
		l[ca][cb]=true;
	}
	c[1][1]=1;
	l[1][1]=true;
	for(int i=1;i!=a+1;i++)
	for(int j=1;j!=b+1;j++)
	if(!l[i][j])
	c[i][j]=c[i-1][j]+c[i][j-1];
	
	
	cout << c[a][b] <<endl;
	system("pause");
	return 0;
}

