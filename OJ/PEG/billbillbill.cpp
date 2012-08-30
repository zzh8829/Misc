#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int acc;
	while(cin >> acc && acc>=0 )
	{
		printf("Account #: %d\n",acc);
		int a,b,c;
		float bill=659;
		cin >> a >>b;
		c=b-a;
		if(c<0) c+= 10000; 
		if(c>10 && c<=30)
		bill+=23.73*(c-10);
		if(c>30 && c<=85)
		bill+=22.71*(c-30)+23.73*20;
		if(c>85 && c<=170)
		bill+=21.78*(c-75)+23.73*20+22.71*55;
		if(c>170)
		bill+=20.85*(c-170)+23.73*20+22.71*55+21.78*85;
		
		printf("Bill: %0.2f\n",bill/100.0);
	}	
	system("pause");
	return 0;
}
