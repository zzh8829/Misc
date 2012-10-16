// Suffix Array using Doubling Algorithm.
#include <iostream>
#include <string>
using namespace std;
const int maxn = 5002;
int s[maxn]; // input string
int rank[maxn];  // Rank
int sa[maxn];	// Suffix Array
int height[maxn];	// Height of S.A.
int wa[maxn],wb[maxn],wss[maxn],wv[maxn]; // Temp arrays

int cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void DA(int *r,int *sa,int n,int m)   
// Doubling Algorithm(array, S.A.,length , radix sort range)
{
	int i,j,p,*x=wa,*y=wb,*t; 
    for(i=0;i<m;i++) wss[i]=0; 
    for(i=0;i<n;i++) wss[x[i]=r[i]]++; 
    for(i=1;i<m;i++) wss[i]+=wss[i-1]; 
    for(i=n-1;i>=0;i--) sa[--wss[x[i]]]=i; 
    for(j=1,p=1;p<n;j*=2,m=p) 
    { 
        for(p=0,i=n-j;i<n;i++) y[p++]=i; 
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j; 
        for(i=0;i<n;i++) wv[i]=x[y[i]]; 
        for(i=0;i<m;i++) wss[i]=0; 
        for(i=0;i<n;i++) wss[wv[i]]++; 
        for(i=1;i<m;i++) wss[i]+=wss[i-1]; 
        for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i]; 
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++) 
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++; 
    }
}
void HEIGHT(int *r,int *sa,int n)
// Height of S.A. (array, S.A. ,length)
{
	int i,j,k=0; 
    for(i=1;i<=n;i++) rank[sa[i]]=i; 
    for(i=0;i<n;height[rank[i++]]=k) 
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++); 
}
int main()
{
	int cs;
	cin >> cs;
	while(cs--)
	{
		string in;
		cin >> in;
		int n = in.size();
		for(int i = 0;i!=n;i++)
			s[i] = in[i];
		s[n] = 0; // Add end sign
		DA(s,sa,n+1,128); // Doubling Algorithm
		HEIGHT(s,sa,n);	 // Suffix Array Height
		long long ans = 0;
		for(int i=0;i!=n;i++)
			ans+= n-i-height[rank[i]];
		cout << ans+1 << endl;			
	}
	return 0;
}
