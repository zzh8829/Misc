#define NUM 10
#include<stdio.h>
int i[NUM];
main()
{
	int sum,n,total,k,flag,count=0;
	printf("Please enter requried terms(<=10):");
	scanf("%d",&n);
	printf("          their sum:");
	scanf("%d",&total);
	sum=0;
	k=n;
	i[n]=1;
	printf("There are following possible series:\n");
	while(1)
	{
		if(sum+i[k]<total)
			if(k<=1)
			{i[1]=total-sum;flag=1;}
			else
			{
				sum+=i[k--];
				i[k]=i[k+1];
				continue;
			}
			else if(sum+i[k]>total||k!=1)
			{
				sum-=i[++k];flag=0;
			}
			else flag=1;
			if(flag)
			{
				printf("[%d]:",++count);
				for(flag=1;flag<=n;++flag)
					printf("%d",i[flag]);
				printf("\n");
			}
			if(++k>n)
				break;
			sum-=i[k];
			i[k]++;
	}
}