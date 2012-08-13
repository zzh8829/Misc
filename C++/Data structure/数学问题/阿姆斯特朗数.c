#include<stdio.h>
main()
{
	int i,t,k,a[3];
	printf("There are following Armstrong number smaller than 1000: \n");
	for(i=152;i<1000;i++)
	{
		for(t=0,k=1000;k>=10;t++)
		{
			a[t]=(i%k)/(k/10); /* k/=10  下面略去*/
			k/=10;
		}
		if(a[0]*a[0]*a[0]+a[1]*a[1]*a[1]+a[2]*a[2]*a[2]==i)
			printf("%d ",i);
	}
}

/*阿姆斯特朗数是一个正整数等于其的各位数的立方和如 153=1*1*1+5*5*5+3*3*3 */