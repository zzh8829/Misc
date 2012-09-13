#include <iostream>
#include <string>
using namespace std;
int main() 
{
    int n =0;
    cin >> n;
    string j= "#";
    string p =" ";
    for(int i=n-1;i>=0;i--)
    {
        for(int k=n-i-2;k>=0;k--)
        cout << p ;
        for(int k=i*2;k>=0;k--)
        cout << j ;
        cout <<endl;
    }
    system("pause");
    return 0;
}
