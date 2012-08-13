#include <iostream>
using namespace std;

int max(int a,int b)
{
return a>b?a:b;
}

int main()
{
int table[101][101];
int n;
cin >> n;
for(int i=1;i!=n+1;i++)
for(int j=1;j!=i+1;j++)
{
int in;
cin >> in;
table[i][j]=in;
}

for(int i=n-1;i!=0;i--)
for(int j=1;j!=i+1;j++)
table[i][j]+=max(table[i+1][j],table[i+1][j+1]);

cout << table[1][1]<<endl;
return 0;
}
