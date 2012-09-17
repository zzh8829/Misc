#include <stdio.h>

#define SIDE_N 3
#define LENGTH 3
#define VARIABLES 6

/********定义全局变量*********/
int A,B,C,D,E,F;
int *pt[]={&A,&B,&C,&D,&E,&F};
int *side[SIDE_N][LENGTH]={&A,&B,&C,
			   &C,&D,&E,
			   &E,&F,&A};
int side_total[SIDE_N];

main()
{
	int i,j,t,equal;
	for(j=0;j<VARIABLES;j++)
		*pt[j]=j+1; 	/*初始化排列 1,2,3.....*/

	while(1)
	{
		for(i=0;i<SIDE_N;i++)
		{
			for(t=j=0;j<LENGTH;j++)
				t+=*side[i][j];
			side_total[i]=t;
		}
		for(equal=1,i=0;equal && i<SIDE_N-1;i++)
			if(side_total[i]!=side_total[i+1])	equal=0;
		if(equal)
		{
			for(i=0;i<VARIABLES;i++)
				printf("%4d",*pt[i]);
			printf("\n");
			scanf("%*c");
		}
		for(j=VARIABLES-1;j>0;j--)
			if(*pt[j]>*pt[j-1])	break;
		if(j==0)	break;
		for(i=VARIABLES-1;i>=j;i--)
			if(*pt[i]>*pt[j-1])	break;
		t=*pt[j-1];
		*pt[j-1]=*pt[i];
		*pt[i]=t;
		for(i=VARIABLES-1;i>j;i--,j++)
		{
			t=*pt[j];
			*pt[j]=*pt[i];
			*pt[i]=t;
		}
	}
}

