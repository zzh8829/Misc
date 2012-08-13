#include <iostream>
#include <string>
using namespace std;

string t[4]={" is a deficient number."," is a perfect number."," is an abundant number."};

int f(int n)
{
	int a = 0;
	for(int i=1;i!=n;i++)
	{
	if(n%i==0)
	    a += i;
	}
	cout << a <<endl;
	return n-a;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
	int in;
	cin >> in;
	int p = f(in);
	if(p==0)
	cout << in << t[1] <<endl;
	else if(p<0)
	cout << in << t[2] << endl;
	else 
	cout << in << t[0] <<endl;
	}
	return 0;
}
