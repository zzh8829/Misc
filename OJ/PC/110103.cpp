#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	while(cin>> n && n !=0)
	{
		double table[1001],sum=0,ave,max=0,min=0,num;
		for(int i=0;i!=n;i++)
		{
			cin >> num;
			table[i]=num;
			sum+=num;
		}
		ave=floor(100*sum/n+0.5)/100;
		for(int i=0;i!=n;i++)
		{
                if(table[i]-ave>0)
                min+=table[i]-ave;
                else
                max+=ave-table[i];
        }
		printf("$%.2lf\n",(max<min?max:min));
	}
	return 0;
}
