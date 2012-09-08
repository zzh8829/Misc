#include <iostream>
#include <cstdio>
//24-points
using namespace std;

int c[4];
int q[4];
int o[4];

inline int MAX(int a,int b){
	return a>b?a:b;
}

int eval(int a,int o ,int b)
{
	if(o==0)
	return a+b;
	if(o==1)
	return a*b;
	if(o==2)
	return a-b;
	if(o==3 && b!=0 && a%b==0)
	return a/b;
	return -999;
}

int main()
{
	int n;
	cin >> n;
	for(int hs=0;hs!=n;hs++)
	{
		for(int i=0;i!=4;i++)
		{
			cin >> c[i];
			q[i]=i;
		}
		int max=0;
		do
		{
			for(int i=0;i!=4;i++)
			for(int j=0;j!=4;j++)
			for(int k=0;k!=4;k++)
			{
				int t[5];
				t[0]=eval(eval(eval(c[q[0]],i,c[q[1]]),j,c[q[2]]),k,c[q[3]]); //((a+b)+c)+d
				t[1]=eval(eval(c[q[0]],i,eval(c[q[1]],j,c[q[2]])),k,c[q[3]]); //(a+(b+c))+d
				t[2]=eval(eval(c[q[0]],i,c[q[1]]),j,eval(c[q[2]],k,c[q[3]])); //(a+b)+(c+d)
				t[3]=eval(c[q[0]],i,eval(c[q[1]],j,eval(c[q[2]],k,c[q[3]]))); //a+(b+(c+d))
				t[4]=eval(c[q[0]],i,eval(eval(c[q[1]],j,c[q[2]]),k,c[q[3]])); //a+((b+c)+d)
				for(int a=0;a!=5;a++)
				{
					if(t[a]>24) continue;
					if(max<t[a]) max=t[a];
				}
				if(max==24) break;
			}
			if(max ==24)
				break;					
		}while( next_permutation(q,q+4) );
		cout << max <<endl;
	}	
	system("pause");
	return 0;
}
