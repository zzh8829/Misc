#include <iostream>
using namespace std;
int main()
{
	int ay = 1989;
	int am = 2;
	int ad = 27;

	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		int y,m,d;
		cin >> y >> m >>d;
		if(y<1989)
		cout << "Yes" <<endl;
		else if(y==1989)
		{
			if(m<2)
			cout << "Yes" <<endl;
			else if(m==2)
			{
				if(d<=27)
				cout <<"Yes" <<endl;
				else 
				cout <<"No" <<endl;
			}
			else cout << "No" <<endl;
		}
		else cout << "No" <<endl;
	}
	return 0;
}