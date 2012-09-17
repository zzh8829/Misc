/*
ID: zzh8829
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <cstring>

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
	ifstream cin("palsquare.in");
	ofstream cout("palsquare.out");
	int base;
	cin >> base;
	for(int i=1;i!=301;i++)
	{
		char buffer[33];
		char buffer2[33];
		int temp=i*i;
		if(pal(mitoa(temp,buffer,base)))
			cout  <<mitoa(i,buffer2,base)<<" "<< buffer <<endl;
	}
	//system("pause");
	return 0;
}
