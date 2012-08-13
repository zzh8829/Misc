#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
int T;
cin>> T;
for(int runs=0;runs!=T;runs++)
{
long long  x,a,b;
cin>>x>>a>>b;
stringstream ss;
ss<<x;
string xl;
ss>>xl;
long long cnt=0;
int sz=xl.size();
long long ct=b-a+1;
for(long long i=0;i!=ct;i++)
{
stringstream sss;
sss << a;
string al;
sss >>al;
if(sz>al.size())
{
a++;
continue;
}
if(xl.compare(0,sz,al,al.size()-sz,sz)==0)
    cnt++;
a++;
}
cout << cnt <<endl;
}
return 0;
}
