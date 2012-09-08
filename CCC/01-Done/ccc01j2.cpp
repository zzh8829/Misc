#include <iostream>
using namespace std;

int main()
{
	int a,b,i;
	cin >> a >>b;
	for(i=0;i!=b;i++)
	if((a*i)%b==1)
	break;
	if(i!=b)
	cout << i <<endl;
	else cout <<"No such integer exists." <<endl;
	return 0;
}