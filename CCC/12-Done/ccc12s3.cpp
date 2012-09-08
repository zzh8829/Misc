#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define getMax(a,b) a>b?a:b
using namespace std;

int nums[1002]={0};

int main()
{
	int n;
	cin >> n;
	int in;
	for(int i=0;i!=n;i++)
	{	
		scanf("%d",&in);
		nums[in]++;
	}
	int max = 0;
	for(int i=1;i!=1001;i++)
	{
		if(nums[i])
		{
			if(nums[max] < nums[i])
			{
				max = i;
			}
		}
	}
	int nmaxs=0;
	int maxs[1002];	
	for(int i=0;i!=1001;i++)
	{
		if(nums[i] == nums[max])
		{
			maxs[nmaxs++]=i;
		}
	}
	if(nmaxs >1)
	{
//		cout << nmaxs <<endl;
//		for(int i=0;i!=nmaxs;i++)
//		cout << maxs[i]<<" ";
//		cout <<endl;
		std::sort(maxs,maxs+nmaxs);
		cout << maxs[nmaxs-1]-maxs[0] <<endl;
	} else {
		int max2 = 0;
		for(int i=1;i!=1001;i++)
		{
			if(nums[i]&&nums[i]!=nums[max])
			{
				if(nums[max2] < nums[i])
				{
					max2 = i;
				}
			}
		}
		int nmax2s=0;
		int max2s[1002];
		for(int i=1;i!=n+1;i++)
		{
			if(nums[i] == nums[max2])
			{
				max2s[nmax2s++]=i;
			}
		}
		std::sort(max2s,max2s+nmax2s);
		int maxmax=maxs[nmaxs-1];
		int minmax=maxs[0];
		int maxmax2=max2s[nmax2s-1];
		int minmax2=max2s[0];
		int d1= abs(maxmax-minmax2);
		int d2= abs(maxmax-maxmax2);
		int d3= abs(minmax-maxmax2);
		int d4= abs(minmax-minmax2);
		int ans = getMax(getMax(d1,d2),getMax(d3,d4));
		cout << ans <<endl;
	}
	
	system("pause");
	return 0;
}
