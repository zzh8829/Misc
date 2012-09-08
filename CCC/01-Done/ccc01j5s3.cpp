#include <iostream>
#include <cstdio>
using namespace std;

int r[600][600],rn[600],c[600][2],n,total;
bool d[600];

bool cut(int st,int no)
{
	if(d[st])
		return true;
	d[st]=true;
	if(st==1)
		return false;
	for(int i=0;i!=rn[st];i++)
	{
		if(st==c[no][0] && r[st][i]==c[no][1]) continue;
		if(st==c[no][1] && r[st][i]==c[no][0]) continue;
		if(!cut(r[st][i],no))
			return false;
	}
	return true;
}

int main()
{
	char a,b;
	while(cin >> a >>b && a!='*')
	{
		r[a-'A'][rn[a-'A']++]=b-'A';
		r[b-'A'][rn[b-'A']++]=a-'A';
		c[n][0]=a-'A';
		c[n++][1]=b-'A';
	}
	for(int i=0;i!=n;i++)
	{
		for(int j=0;j!=590;j++)
			d[j]=false;
		if(cut(0,i))
		{
			cout << char(c[i][0]+'A')<< char(c[i][1]+'A') <<endl;
			total++;
		}
	}	
	printf("There are %d disconnecting roads.\n",total);
	system("pause");
	return 0;
}
