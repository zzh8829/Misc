#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int t=0;t!=n;++t)
	{
		int num,nasty = 0;
		cin >> num;
		for(int i=1;i<=num;i++) if(num%i==0)
			for(int j=1;j<=num && j!=i;j++) if(num%j==0)
				if(abs(i-num/i) == j+num/j)
				{
					nasty = 1;
					break;
				}	
		if(nasty)
			cout << num << " is nasty" <<endl;
		else
			cout << num <<" is not nasty"<<endl;
	}	
	system("pause");
	return 0;
}
