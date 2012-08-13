#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		int A, B;
		cin >> A >> B;
		int ans=0;
		int a=A-1;
		int b=(B-1)*A;
		ans = a+b;
		cout << ans <<endl;
	}
	system("pause");
	return 0;
}
