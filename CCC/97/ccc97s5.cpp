#include <iostream>
#include <cstdio>

using namespace std;

int a[81],b[81],la,lb;
int s[81],ls;
char buf[81];
bool aGb(int len)
{
	if(la<lb)return false;
	for(int i=0;i!=len;i++)
	{
		if(a[la-i-1] > b[len-i-1])
			return true;
		else if(a[la-i-1] <b[len-i-1])
			return false;
	}
	return true;	
}

void sub(int len)
{
	while(aGb(len))
	{
		s[ls]++;
		int i;
		for(i=0;i!=len;i++)
		{
			a[la-i-1]-=b[len-i-1];
		}
		for(i=0;i!=la;i++)
		{
			if(a[i]<0)
			{
				a[i]+=10;
				a[i+1]-=1;
			}
		}
		if(a[la-1]==0)
		{
			while(a[la-1]==0 && la!=0)
			{
				if(!b[len-1])
				{
					len--;
					la--;
				}
				else
					break;
			}
		}
	}
	if(la<len+1)
		return;
	ls--;
	sub(len+1);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int t=0;t!=n;t++)
	{
		int ts;
		for(int i=0;i!=81;i++)
		{
			a[i]=b[i]=s[i]=0;
		}
		scanf("%s",buf);
		la=strlen(buf);
		for(int i=0;i!=la;i++)
			a[la-i-1] = buf[i]-'0';
		scanf("%s",buf);
		lb=strlen(buf);
		for(int i=0;i!=lb;i++)
			b[lb-i-1] = buf[i]-'0';
		ts=ls=la-lb;
		sub(lb);
		if(ts<=0) ts=1;
		while(s[ts]==0 && ts!=0)
			ts--;
		while(a[la-1]==0 && la!=1)
			la--;
		for(int i=0;i<=ts;i++)
			cout << s[ts-i];
		cout <<endl;
		for(int i=0;i!=la;i++)
			cout << a[la-i-1];
		cout <<endl;
		cout <<endl;
	}

	system("pause");
	return 0;
}
