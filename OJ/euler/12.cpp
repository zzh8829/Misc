#include <iostream>
#include <cstdio>
using namespace std;
long long triangle[2000000],table[2000000];
int tn=1;
void tri()
{
int d=2;
triangle[1]=1;
for(int i=2;i!=2000000;i++)
{
triangle[i]=triangle[i-1]+d;
d++;
if(triangle[i]%6==0)
table[tn++]=triangle[i];
}
}

int fact(long long n)
{
int cnt=2;
for(long long i=2;i<(n/2)+1;i++)
if(n%i==0)
cnt++;
return cnt;
}

int main()
{
tri();
int i=1;
for(i=1;i!=tn;i++)
{
int c=fact(table[i]);
printf("_%d_" ,c);
if(c>=500)
    break;
}
//cout << fact(triangle[7])<<endl;
cout << table[i]<<endl;
return 0;
}
