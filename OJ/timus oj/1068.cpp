//1068

#include <iostream>
using namespace std;

int main()
{
    long long n;
	cin >> n;
	if(n<0)
		cout << ((-1+n)*-n)/2+1;
	else if (n>0)
		cout << ((1+n)*n)/2 << endl;
	else cout << 1 << endl;
	return 0;
}
