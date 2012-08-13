#include <iostream>
#include <cmath>
using namespace std;

int main()
{
while(1){
float num,ave,sum=0;
for(int i=0;i!=12;i++)
{
cin >> num;
sum+=num;
}
ave=(sum)/12;
ave= floorf(ave*100+0.5)/100;
cout << "$"<<ave;
}
system("pause");
return 0;
}

