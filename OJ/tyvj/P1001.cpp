#include <iostream>
#include <algorithm>
using namespace std;

int array[10001],n,k;
bool prime(int n)
{
	if(n<2)
		return false;
	if(n==2)
        return true;
	for(int i=2;i*i<n+1;i++)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	cin >> n >> k;
	int in;
	for(int i=0;i!=n;i++)
	{
		cin >> in;
		array[i]=in;
	}
	sort(array,array+n);
	int m=array[n-k]-array[k-1];
	if(prime(m))
		cout << "YES" <<endl;
	else
		cout << "NO" <<endl;
	cout << m <<endl;
	system("pause");
	return 0;
}
