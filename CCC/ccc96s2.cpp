#include <iostream>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		int in[51];
		string ins;
		cin >> ins;
		int len = ins.size();
		for(int i=0;i!=len;i++)
		{	
			in[i] = (char)ins[i] -'0';
		}
		while(len > 1)
		{
			int 