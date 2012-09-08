#include <iostream>
#include <string>
using namespace std;

int N[255];

int main()
{
	N['I']=1;
	N['V']=5;
	N['X']=10;
	N['L']=50;
	N['C']=100;
	N['D']=500;
	N['M']=1000;
	char in[21];
	int n=0;
	char input;
	while(cin>>input)
	in[n++]=input;
	int ans=0;
	for(int i=0;i!=n/2-1;i++)
	{
		int d=i*2;
		int t =int(in[d]-'1'+1)*N[in[d+1]];
		if(N[in[d+3]] > N[in[d+1]])
		ans-=t;
		else
		ans+=t;
	}
	ans+= int(in[n-2]-'1'+1) *N[in[n-1]];	
	cout << ans <<endl;	
	return 0 ;
}
