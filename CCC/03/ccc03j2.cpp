#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int area;
	while(cin >> area && area!=0)
	{
		int tmp = sqrt(area)+1;
		for(int i=tmp;i!=0;i--)
		{
			if(area%i ==0 )
			{
				int a = area/i;
				int p = 2*(a+i);
				printf("Minimum perimeter is %d with dimensions %d x %d\n",p,i,a);
				break;
			}
		}
	}
	return 0;
}
