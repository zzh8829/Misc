#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a,b;
	string in,mid=" as ",as[6],bs[6];
	cin >> a >> b;
	cin.ignore();
	for(int i=0;i!=a;i++)
	cin >> as[i];
	for(int i=0;i!=b;i++)
	cin >> bs[i];
	for(int i=0;i!=a;i++)
	for(int j=0;j!=b;j++)
	cout << as[i] << mid << bs[j] <<endl;
	return 0;
}