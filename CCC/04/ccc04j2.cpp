#include <cstdio>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int nums= (b-a+60)/60;
	for(int i=0;i!=nums;i++)
	printf("All positions change in year %d\n",a+i*60);
	return 0;
}