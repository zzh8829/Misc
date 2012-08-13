#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
}r[20];

struct rnode
{
	int key;
	int point;
};

main()
{
	void print(struct node a[20],int n);
	int creat();
	void shell(struct node a[20],int n);
	int hoare(struct node a[20],int l,int h);
	void quick1(struct node a[20],int n);
	void quick2(struct node a[20],int l,int h);
	void heap(struct node a[20],int i,int m);
	void heapsort(struct node a[20],int n);
	void merges(struct node a[20],struct node a2[20],int h1,int mid,int h2);
	void mergepass(struct node a[20],struct node a2[20],int l,int n);
	void mergesort(struct node a[20],int n);
	int yx(int m,int i);
	int radixsort(struct rnode a[20],int n);
	int num,l,h,c;
	struct rnode s[20];
	c=1;
	while(c!=0)
	{
		printf("        主菜单                       \n");
		printf("   1    输入关键字，以-9999表示结束。\n");
		printf("   2    希尔排序                     \n");
		printf("   3    非递归的快速排序             \n");
		printf("   4    递归的快速排序               \n");
		printf("   5    堆排序                       \n");
		printf("   6    归并排序                     \n");
		printf("   7    基数排序                     \n");
		printf(" 输入选择    (1--7,0表示结束):         ");
		scanf("%d",&c);
		switch(c)
		{
		case 1:num=creat();print(r,num);break;
		case 2:shell(r,num);print(r,num);break;
		case 3:quick1(r,num);print(r,num);break;
		case 4:l=0;h=num-1;quick2(r,l,h);
			printf("output quick2sort result:\n");
			print(r,num);break;
		case 5:heapsort(r,num);break;
		case 6:mergesort(r,num);print(r,num);break;
		case 7:radixsort(s,num);
		}
	}
}//main end

void print(struct node a[20],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%5d",a[i ].key);
	printf("\n");
}//print end

int creat()
{
	int i,n;
	n=0;
	printf("input keys");
	scanf("%d",&i);
	while(i!=-9999)
	{
		r[n].key=i;
		n++;
		scanf("%d",&i);
	}
	return(n);
}//creat end

void shell(struct node a[20],int n)//希尔排序
{
	int i,j,k;
	for(i=n;i>=1;i--)
		a[i].key=a[i-1].key;
	k=n/2;
	while(k>=1)
	{
		for(i=k+1;i<=n;i++)
		{
			a[0].key=a[i].key;
			j=i-k;
			while((a[j].key>a[0].key)&&(j>=0))
			{
				a[j+k].key=a[j].key;
				j=j-k;
			}
			a[j+k]=a[0];
		}
		k=k/2;
	}
	for(i=0;i<n;i++)
		a[i].key=a[i+1].key;
	printf("输出希尔排序的结果:\n");
}//shell end

////////////////////快速排序///////////////////////////

int hoare(struct node a[20],int l,int h)//分区处理函数
{
	int i,j;
	struct node x;
	i=l;
	j=h;
	x.key=a[i].key;
	do
	{
		while((i<j)&&(a[j].key>=x.key))
			j--;
		if(i<j)
		{
			a[i].key=a[j].key;
			i++;
		}
		while((i<j)&&(a[i].key<=x.key))
			i++;
		if(i<j)
		{
			a[j].key=a[i].key;
			j--;
		}
	}while(i<j);
	a[i].key=x.key;
	return(i);
}//hoare end

void quick1(struct node a[20],int n)
{
	int i,l,h,tag,top;
	int s[20][2];
	l=0;h=n-1;tag=1;top=0;
	do
	{
		while(l<h)
		{
			i=hoare(a,l,h);
			top++;
			s[top][0]=i+1;
			s[top][1]=h;
			h=h-1;
		}
		if(top==0)
			tag=0;
		else
		{
			l=s[top][0];
			h=s[top][1];
			top--;
		}
	}while(tag==1);
	printf("输出非递归快速排序结果:\n");
}//quick end

void quick2(struct node a[20],int l,int h)//递归的快速排序
{
	int i;
	if(l<h)
	{
		i=hoare(a,l,h);
		quick2(a,l,i-1);
		quick2(a,i+1,h);
	}
}//quick2 end

////////////////////快速排序结束////////////////////////

////////////////////堆排序函数//////////////////////////

void heap(struct node a[20],int i,int m)//调整堆的函数
{
	struct node x;
	int j;
	x.key=a[i].key;
	j=2*i;
	while(j<=m)
	{
		if(j<m)
			if(a[j].key>a[j+1].key)
				j++;
		if(a[j].key<x.key)
		{
			a[i].key=a[j].key;
			i=j;
			j=2*i;
		}
		else
			j=m+1;
	}
	a[i].key=x.key;
}//heap end

void heapsort(struct node a[20],int n)//堆排序的主体函数
{
	int i,v;
	struct node x;
	for(i=n;i>0;i--)
		a[i].key=a[i-1].key;
	for(i=n/2;i>=1;i--)
		heap(a,i,n);
	printf("输出堆排序结果:\n");
	for(v=n;v>=2;v--)
	{
		printf("%5d",a[1].key);
		x.key=a[1].key;
		a[1].key=a[v].key;
		a[v].key=x.key;
		heap(a,1,v-1);
	}
	printf("%5d",a[1].key);
	for(i=0;i<n;i++)
		a[i].key=a[i+1].key;
}//heapsort end

/////////////////堆排序函数结束///////////////////

//////////////////归并函数////////////////////////

void merges(struct node a[20],struct node a2[20],int h1,int mid,int h2)
//归并排序的核心算法
{
	int i,j,k;
	i=h1;j=mid+1;k=h1-1;
	while((i<=mid)&&(j<=h2))
	{
		k=k+1;
		if(a[i].key<=a[j].key)
		{
			a2[k].key=a[i].key;
			i++;
		}
		else
		{
			a2[k].key=a[j].key;
			j++;
		}
	}
	while(i<=mid)
	{
		k++;
		a2[k].key=a[i].key;
		i++;
	}
	while(j<=h2)
	{
		k++;
		a2[k].key=a[j].key;
		i++;
	}
}//merges end

void mergepass(struct node a[20],struct node a2[20],int l,int n)
//一趟归并
{
	int j,i,h1,mid,h2;
	i=0;
	while((n-i)>=2*l)
	{
		h1=i;
		mid=h1+l-1;
		h2=i+2*l-1;
		merges(a,a2,h1,mid,h2);
		i=i+2*l;
	}
	if((n-i)<=l)
		for(j=i;j<=n;j++)
			a2[j].key=a[j].key;
	else
	{
		h1=i;
		mid=h1+l-1;
		h2=n-1;
		merges(a,a2,h1,mid,h2);
	}
}//mergepass end

void mergesort(struct node a[20],int n)
{
	int l;
	struct node a2[20];
	l=1;
	while(l<n)
	{
		mergepass(a,a2,l,n);
		l=2*l;
		mergepass(a2,a,l,n);
		l=2*l;
	}
	printf("输出归并排序的结果:\n");
}//mergesort end

///////////////归并函数结束///////////////

///////////////基数排序///////////////////

int yx(int m,int i)//分离关键字倒数第i位有效数字的算法
{
	int x;
	switch(i)
	{
	case 1:x=m%10;break;
	case 2:x=(m%100)/10;break;
	case 3:x=(m%1000)/100;break;
	case 4:x=(m%10000)/1000;break;
	}
	return(x);
}//yx end

int radixsort(struct rnode a[20],int n)
{
	int f[11],e[11],i,j,k,l,p,d,t;
	for(i=1;i<=n;i++)
	{
		a[i].key=r[i-1].key;
		a[i].point=i+1;
	}
	a[n].point=0;
	p=1;
	printf("输出关键字有效位数 d\n");
	scanf("%d",&d);
	printf("输出基数排序的结果:\n");
	for(i=1;i<=d;i++)
	{
		for(j=0;j<=10;j++)
		{
			f[j]=0;
			e[j]=0;
		}
		while(p!=0)
		{
			k=yx(a[p].key,i);
			if(f[k]==0)
			{
				f[k]=p;
				e[k]=p;
			}
			else
			{
				l=e[k];
				a[l].point=p;
				e[k]=p;
			}
			p=a[p].point;
		}
		j=0;
		while(f[j]==0)
			j++;
		p=f[j];t=e[j];
		while(j<10)
		{
			j++;
			while((j<10)&&(f[j]==0))
				j++;
			if(f[j]!=0)
			{
				a[t].point=f[j];
				t=e[j];
			}
		}
		a[t].point=0;
		t=p;
		while(t!=0)
		{
			printf("%5d",a[t].key);
			t=a[t].point;
		}
		printf("\n");
	}
	return(p);
}

