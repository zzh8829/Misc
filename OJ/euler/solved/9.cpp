#include <iostream>
using namespace std;

int main()
{

for(int i=1;i!=999;i++)
for(int j=1;j!=1000-i;j++)
if(i*i+j*j==(1000-i-j)*(1000-i-j))
cout << i*j*(1000-i-j)<<endl;
return 0;
}
