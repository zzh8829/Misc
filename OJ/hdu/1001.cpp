#include<iostream>
using namespace std;

long sum(long num)
{
long sum=0;
for(long i=1;i!=num+1;i++)
sum+=i;
return sum;
}


int main()
{
long num;
while(cin>>num)
{
cout<<sum(num)<<endl;
}
return 0;
}
