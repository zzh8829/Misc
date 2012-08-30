#include <iostream>

using namespace std;
int main()
{
int a,b,c;
cin >> a >> b >>c;
int t = a*b + (c-1 )*a + (c-1)*(b-1);
cout << t <<endl;
system("pause");
return 0;
}
