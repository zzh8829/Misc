#include <iostream>
using namespace std;
int main()
{
    float a,b,c,d,e,f,g,h,i,j,k,l,m;
    cin >>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
    m= (a+b+c+d+e+f+g+h+i+j+k+l+m)/12;
    int n=(m*1000);
    float r=n/1000.0;
    int nnnn=(m*100);
    float rrrr=m/100.0;
    float x=r-rrrr;
    if(x>=0.005)
    r+=0.01;
    int nn=(r*100);
    float rr=nn/100.0;
    cout <<"$"<<rr<<endl;
    system("pause");
    return 0;
}
