#include <iostream>
using namespace std;

int P(int x,int y)
{
	int ans = 1;
	for(int i=0;i!=y;i++)
	ans*=(x-i);
	return ans;
}

int main()
{
	int n;
	cin >> n;
	if(n<4)
	cout << 0 <<endl;
	else
	cout << P(n-1,3)/6 <<endl;
	system("pause");
	return 0;
}
