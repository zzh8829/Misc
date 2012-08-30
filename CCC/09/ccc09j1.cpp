#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int base = 91;
	int a,b,c;
	cin >> a >> b >> c;
	int sum = base + a + 3*b + c;
	printf("The 1-3-sum is %d\n",sum);
	return 0;
}