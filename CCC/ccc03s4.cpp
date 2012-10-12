#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[400001],w[200001],r[400001],s[400001],tr[400001],ts[400001],h[400001];
//h[i]表示排名为i和排名为i-1的后缀的最长公共前缀
//r[i]表示从第i个字符开始的后缀的排名
//s[i]表示排名为i的后缀从第几个字符开始
//tr和r类似，倍增的时候用的
//ts和s类似，倍增的时候用的
char x;
int main()
{
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;a[i]=x-96;
		w[a[i]]++;
	}
	for(i=1;i<=26;i++)
		w[i]+=w[i-1];
	for(i=n;i>=1;i--)
		s[w[a[i]]--]=i;
	j=1;
	r[s[1]]=1;
	for(i=2;i<=n;i++)
	{
		if(a[s[i]]!=a[s[i-1]])j++;
		r[s[i]]=j;
	}
	k=j;j=1;
	while(k<n)
	{
		memcpy(tr,r,sizeof(r));
		memset(w,0,sizeof(w));
		for(i=1;i<=n;i++)
		w[r[i+j]]++;
		for(i=1;i<=n;i++)
		w[i]+=w[i-1];
		for(i=n;i>=1;i--)
		ts[w[r[i+j]]--]=i;
		memset(w,0,sizeof(w));
		for(i=1;i<=n;i++)
		{r[i]=tr[ts[i]];w[r[i]]++;}
		for(i=1;i<=n;i++)
		w[i]+=w[i-1];
		for(i=n;i>=1;i--)
		s[w[r[i]]--]=ts[i];
		k=1;
		r[s[1]]=1;
		for(i=2;i<=n;i++)
		{
			if(tr[s[i]]!=tr[s[i-1]]||tr[s[i]+j]!=tr[s[i-1]+j])
			k++;
			r[s[i]]=k;
		}
		j*=2;
	}
	h[1]=0;
	j=0;
	for(i=1;i<=n;i++)
	if(r[i]!=1)
	{
		k=s[r[i]-1];
		while(a[i+j]==a[k+j])
		j++;
		h[r[i]]=j;
		if(j>0)j--;
	}
	long long ans=0;
	for(i=1;i<=n;i++)
	ans+=n-s[i]+1-h[i];
	cout<<ans<<endl;
	return 0;
}

