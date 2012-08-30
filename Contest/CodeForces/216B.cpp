#include <iostream>
using namespace std;
int people[101][2];
int d[103];
void f(int& num,int i)
{
	if(d[i] == 1)
	{
		num--;
		return ;
	}
	d[i] = 1;
	for(int j=0;j!=2;j++)
	{
		if(people[i][j])
		{
			int t =people[i][j];
			people[i][j] = 0;
			num++;
			f(num,t);
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int p=0;p!=m;p++)
	{
		int a,b;
		cin >> a >>b;
		if(people[a][0])
		people[a][1] = b;
		else
		people[a][0] = b;
	}
	int kik  = 0;
	for(int i=1;i<=n;i++)
	{
		if(people[i][0] || people[i][1])
		{
		for(int j=0;j!=102;j++)
		d[j] = 0;
		int num = 1;
		f(num,i);
		if(num%2 != 0)
		kik++;
		}	
	}
	if( (n-kik) %2 != 0)
	kik++;
	cout << kik <<endl;
	system("pause");
	return 0;
}
