//24-points
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int c[4],q[4],o[4];
char op[4]={'+','*','-','/'};

void output(int n1,int n2,int n3,int n4,char o1,char o2,char o3,int type)
{
	switch(type)
	{
	case 0:	printf("((%d%c%d)%c%d)%c%d\n",n1,o1,n2,o2,n3,o3,n4); break;
	case 1: printf("(%d%c(%d%c%d))%c%d\n",n1,o1,n2,o2,n3,o3,n4); break;		 
	case 2: printf("(%d%c%d)%c(%d%c%d)\n",n1,o1,n2,o2,n3,o3,n4); break;
	case 3: printf("%d%c(%d%c(%d%c%d))\n",n1,o1,n2,o2,n3,o3,n4); break;
	case 4: printf("%d%c((%d%c%d)%c%d)\n",n1,o1,n2,o2,n3,o3,n4); break;
	}
}
int eval(int a,int o ,int b)
{
	if(o==0)return a+b;
	if(o==1)return a*b;
	if(o==2)return a-b;
	if(o==3 && b!=0 && a%b==0)return a/b;
	return -999999;
}

int main()
{
	while(cin>> c[0] >>c[1]>>c[2]>>c[3])
	{
		for(int i=0;i!=4;i++)
			q[i]=i;
		do
		{
			for(int i=0;i!=4;i++)
			for(int j=0;j!=4;j++)
			for(int k=0;k!=4;k++)
			{
				int t[5]={0};
				t[0]=eval(eval(eval(c[q[0]],i,c[q[1]]),j,c[q[2]]),k,c[q[3]]);
				t[1]=eval(eval(c[q[0]],i,eval(c[q[1]],j,c[q[2]])),k,c[q[3]]); 
				t[2]=eval(eval(c[q[0]],i,c[q[1]]),j,eval(c[q[2]],k,c[q[3]])); 
				t[3]=eval(c[q[0]],i,eval(c[q[1]],j,eval(c[q[2]],k,c[q[3]])));
				t[4]=eval(c[q[0]],i,eval(eval(c[q[1]],j,c[q[2]]),k,c[q[3]])); 
				for(int type=0;type!=5;type++)
				if(t[type]==24)
					output(c[q[0]],c[q[1]],c[q[2]],c[q[3]],op[i],op[j],op[k],type);
			}				
		}while( next_permutation(q,q+4));
	}	
	return 0;
}
