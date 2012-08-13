/*
ID: zzh8829
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

char* mitoa(int value, char *string, int radix)
{
	char tmp[33];
	char *tp = tmp;
	int i;
	unsigned v=value;
	char *sp;	
	while (v || tp == tmp)
	{
		i = v % radix;
		v = v / radix;
		if (i < 10)
		*tp++ = i+'0';
		else
		*tp++ = i + 'A' - 10;
	}
	if (string == 0)
	    string = (char *)malloc((tp-tmp)+1);
	sp = string;
	while (tp > tmp)
	*sp++ = *--tp;
	*sp = 0;
	return string;
}
bool pal(char* a)
{
	int len=strlen(a);
	for(int i=0;i!=len/2;i++)
	if(a[i]!=a[len-i-1])
	return false;
	return true;     
}
int main()
{
	//ifstream cin("dualpal.in");
	//ofstream cout("dualpal.out");
	int N,S,cnt=0;
	cin >> N >> S;
	while(cnt!=N)
	{
		S++;
		for(int i=2;i!=11;i++)
		{
			char buffer[33];
			if( pal(mitoa(S,buffer,i)))
			{
				cout << S << " " << i <<" " <<buffer <<endl;
				cnt++;
				break;
			}
		}
	}
	system("pause");
	return 0;
}
