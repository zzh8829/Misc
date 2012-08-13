#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 100005;

int lena,lenb,lenc,na[maxn], nb[maxn],nc[maxn],sa,sb,sc;

bool aIsBigger()
{
	if(lena != lenb) return lena >  lenb;
	for(int i= lena-1;i!= -1;i--)
	if( na[i] != nb[i])
	return na[i] > nb[i];
	return false;
}

int main()
{
	for(int i=0;i!=maxn;i++)
	{
		na[i] = 0;
		nb[i] = 0;
		nc[i] = 0;
	}
	string a ,b;
	cin >> a >> b;
	const char* ia = a.c_str();
	const char* ib = b.c_str();
	// input A
	if(ia[0] == '-')
	sa = -1;
	else
	sa = 1;
	lena = strlen(ia);

	if(sa == 1)
	for(int i=0;i!=lena;i++)
	na[i] = ia[lena-i-1] - '0';
	else
	{
		lena-=1;
		for(int i=0;i!=lena;i++)
		na[i] = ia[lena-i] - '0';
	}
	// input B
	if(ib[0] == '-')
		sb = -1;
	else
		sb = 1;
	lenb = strlen(ib);
	if(sb == 1)
	for(int i=0;i!=lenb;i++)
	nb[i] = ib[lenb-i-1] - '0';
	else
	{
		lenb-=1;
		for(int i=0;i!=lenb;i++)
		nb[i] = ib[lenb-i] - '0';
	}
	
	//a+b
	lenc = 0;
	sc = 1;
	if(sa == sb)
	{
		int length = lena;
		if(lena < lenb) length = lenb;
		for(int i=0; i< length ;i++)
		{
			nc[lenc++] += (na[i] + nb[i]);
			//		cout << nc[lenc-1] << " ";
			if(nc[lenc-1] > 9)
			{
				nc[lenc]++;
				nc[lenc-1] = nc[lenc-1]-10;
			}
		}
		if(nc[lenc])
		lenc++;
		if( sa == -1)
		sc = -1;
	}
	else
	{		
		if(aIsBigger())
		{
			for(int i=0;i != lena;i++)
			{
				nc[lenc] += (na[i] - nb[i]);
				if(nc[lenc] < 0)
				{
					nc[lenc+1]--;
					nc[lenc] =10 + nc[lenc];
				}
				lenc++;
			}
			for(int i= lenc-1 ;i!=-1;i--)
			{
				if( nc[i] )
				break;
				lenc--;
			}
			if(sa == -1)
			sc = -1;
			else
			sc = 1;
		}
		else
		{
			for(int i=0;i != lenb;i++)
			{
				nc[lenc] += (nb[i] - na[i]);
				if(nc[lenc] < 0)
				{
					nc[lenc+1]--;
					nc[lenc] =10 + nc[lenc];
				}
				lenc++;
			}
			for(int i= lenc-1 ;i!=-1;i--)
			{
				if( nc[i] )
				break;
				lenc--;
			}
			if(sb == -1)
			sc = -1;
			else
			sc = 1;
		}
	}
	
	string str= "";
	for(int i=0;i!=lenc;i++)
	str = (char)(nc[i] + '0') + str;
	if(str =="") str = "0";
	if(sc == -1)
	str = "-"+ str;
	cout << str << endl;
	
	system("pause");
	return 0;
}
