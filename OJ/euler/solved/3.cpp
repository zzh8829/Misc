#include <iostream>
using namespace std;

const long long  n=600851475143;
long long ans=0;
bool prime(long long a)
{
for(long long  i=3;i*i<a;i+=2)
if(a%i==0)
return false;
return true;
}

bool valid(long long  a)
{
if(n%a==0)
return true;
return false;
}

int main()
{
    for(long long i=1;i*i<n;i+=2)
        if(valid(i))
            if(prime(i))
                if(i>ans)
                    ans=i;
    cout << ans <<endl;
    return 0;
}

