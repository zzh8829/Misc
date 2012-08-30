#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int n,m,sum=0;
	int ti,Ti,xi,ci;
	cin >> n >> m;
	for(int i=0;i!=n;i++)
	{
		cin >> ti >> Ti>>xi>>ci;
		int tc = ti-Ti;
		// all in one bus
		int all = ci;
		if(tc+m>0)
			all+=m*xi;
		
		int less=0;
		if(tc+1>0)
			less+=m*xi;
		if(tc>=0) 
			tc=-1;
		// min bus
		int bs=m/-tc;
		if(bs==0)
			bs+=2;
		else if(!m%-tc)
			bs+=1;
		less+=bs*ci;		
		int add=all<less?all:less;
	//	cout << add << " " << all << " " << less <<" "<<endl;
		sum+=add;
	}
	cout << sum <<endl;	
	system("pause");
	return 0;
}
