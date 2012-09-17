/*
ID: zzh8829
PROG: milk
LANG: C++
*/
#include <fstream>
#include <iostream>
using namespace std;
struct Milk
{
	int price;
	int amount;
	bool used;
}milk[5000]={0,0,false};
int main()
{
	ifstream cin("milk.in");
	ofstream cout("milk.out");
	int N,M,sum=0;
	cin >> N >> M;
	int a,b;
	for(int i=0;i!=M;i++)
	{
		cin >> a>> b;
		milk[i].price=a;
		milk[i].amount=b;
		milk[i].used=false;
	}
	for(int j=0;j!=M&&N!=0;j++)
	{
		int price=1001,amount=0,provider;
		for(int D=0;D!=M;D++)
			if(milk[D].used==false&&milk[D].price<price)
			{ 
				price=milk[D].price;
				provider=D;
			}
		amount=milk[provider].amount;
		if(amount>N)
			amount=N;
		sum+=amount*price;
		N-=amount;
		milk[provider].used=true;
	}
	cout << sum <<endl;
	//system("pause");
	return 0;
}
		