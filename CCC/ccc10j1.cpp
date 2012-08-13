#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n<6)
	cout << n/2+1 <<endl;
	else
	cout << (10-n)/2+1 <<endl;
	return 0;
}