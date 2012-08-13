#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
string str="";

for(int i=0;str.size()<1000002;i++)
{
stringstream ss;
ss << i;
str+=ss.str();
}
int ans=1;
for(int i=0;i!=7;i++)
{
int v=int(str[pow(10,i)])-48;
ans *= v;
}
cout << ans <<endl;
return 0;
}
