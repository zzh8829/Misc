#include <iostream>
#include <algorithm>
using namespace std;
int sc[51];

int main()
{
int n,k;
cin >> n >> k;
int ans=k;
for(int i=0;i!=n;i++)
{
int in;
cin >> in;
sc[i]=in;
}
sort(sc,sc+n);
while(ans<=(n-1)&&sc[n-ans]==sc[n-ans-1])
    ans++;

for(int i=0;i!=ans;i++)
if(sc[n-1-i]==0)
{ans=i;
break;
}
cout << ans <<endl;
return 0;
}

