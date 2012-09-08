#include <iostream>
#include <cstdio>
using namespace std;
int len,a[100001],b[100001];
int main()
{
	int n;
	scanf("%d",&n);
	for(int cs=0;cs!=n;cs++)
	{
		int fo=0,ok=1;
		cin >> len;
		for(int i=0;i!=len;i++)
		scanf("%d",&a[i]);
		for(int i=0;i!=len;i++)
		{
			scanf("%d",&b[i]);
			if( !fo && b[i]>=a[i] && ok)
			{
				ok=0;
				fo=i;
			}
		}
		int max=0;
		for(int i=fo;i!=len;i++)
		{
			int j=i+max;
			while(j<len && b[j]>=a[i])
				j++;
			j--;
			if(j>=len) continue;
			max=j-i>max?j-i:max;
		}
		printf("The maximum distance is %d\n", max);
	}	
	system("pause");
	return 0;
}
