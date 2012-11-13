#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		int a[101]={0};
		for (int i = 0; i < N; ++i)
			cin >> a[i];
		sort(a,a+N);
		cout << a[N-1] << endl;
	}	
	return 0;
}