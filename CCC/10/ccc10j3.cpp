#include <iostream>
#include <cstdio>

using namespace std;

int num[256];

int main()
{
	int state ,n;
	num['B'] = num['A'] = 0;
	char x,y;
	while(cin >> state && state!=7)
	switch(state)
	{
		case 1:
			cin >> x >> n;
			num[x] = n;
			break;
		case 2:
			cin >> x;
			cout << num[x] <<endl;
			break;
		case 3:
			cin >> x >> y;
			num[x] = num[x] + num[y];
			break;
		case 4:
			cin >> x >> y;
			num[x] = num[x] * num[y];
			break;
		case 5:
			cin >> x >> y;
			num[x] = num[x] - num[y];
			break;
		case 6:
			cin >> x >> y;
			num[x] = num[x]/num[y];
			break;
	}
	system("pause");
	return 0;
}
