#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    cin >> n>> m;
    double ans=0;
    for(int i=n;i<=m;i++)
    {
        double t=(1.0/i)*(1.0/i);
        ans+=t;
    }
    printf("%.5lf\n",ans);
    system("pause");
    return 0;
}
