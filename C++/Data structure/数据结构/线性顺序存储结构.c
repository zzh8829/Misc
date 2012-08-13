#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define ELEMTP int
#define v (*p)

struct sequnce
{
	ELEMTP elem[MAX];
	int len;
};

main()
{
	struct sequnce *pz;
	int i,y,cord;
	void outlin(struct sequnce s);
	void create(struct sequnce *p);
	void insert(struct sequnce *p,int i,int x);
	void deletes(struct sequnce *p,int i);
	do{
		printf("\n        主菜单        \n");
		printf("     1   建立线性表     \n");
		printf("     2   插入一个元素   \n");
		printf("     3   删除一个元素   \n");
		printf("     4   结束程序运行   \n");
		printf("------------------------------------\n");
		printf(" 请输入您的选择(1, 2, 3, 4) ");
		scanf("%d",&cord);
		switch(cord)
		{
			case 1:
			{
				pz=(struct sequnce *)malloc(sizeof(struct sequnce));
				create(pz);
				outlin(*pz);
			}break;
			case 2:
			{
				printf("请输入插入的位置 i: ");
				scanf("%d",&i);
				printf("请输入插入的数据 y: ");
				scanf("%d",&y);
				insert(pz,i,y);
				outlin(*pz);
			}break;
			case 3:
			{
				scanf("%d",&i);
				deletes(pz,i);
				outlin(*pz);
			}break;
			case 4:
				exit(0);
		}
	}while(cord<=4);
}

void outlin(struct sequnce s)
{
	int i;
	for(i=1;i<=s.len;i++)
		printf("%2d%6d\n",i,s.elem[i]);
}

void deletes(struct sequnce *p,int i)
{
	int j;
	if(i<1||i>v.len)
		printf("i, 位置不存在 ");
	else
	{
		for(j=i;j<v.len;j++)
			v.elem[j]=v.elem[j+1];
		v.len--;
	}
}

void insert(struct sequnce *p,int i,int x)
{
	int j;
	if(i<1||i>v.len+1)
		printf("i 位置不存在。");
	else
	{
		for(j=v.len;j>=i;j--)
			v.elem[j+1]=v.elem[j];
		v.elem[i]=x;
		v.len++;
	}
}

void create(struct sequnce *p)
{
	int i;
	printf("n= ");
	scanf("%d",&(v.len));
	for(i=1;i<=v.len;i++)
	{
		printf("data= ");
		scanf("%d",&(v.elem[i]));
	}
}
