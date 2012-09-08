#include <iostream>
using namespace std;

int m[11] = {0,100,500,1000,5000,10000,25000,50000,100000,500000,1000000};
int main()
{
	int n;
	cin >> n;
	int in;
	int sum = 1691600;
	for(int i=0;i!=n;i++)
	{
		cin >> in;
		sum -= m[in];
	}
	int offer;
	cin >> offer;
	if(offer > sum/(10-n))
	cout << "deal" <<endl;
	else
	cout << "no deal" <<endl;

	return 0;
}
		
	
