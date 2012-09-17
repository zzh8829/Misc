/*
ID: zzh8829
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int n,num[10],in,ans=0,p1,p2,fp,sp,sum;
bool h[10]={false};

bool find(int i)
{
	if(i<1000&&i>100)
		if(h[i%10]&&h[(i/10)%10]&&h[i/100])
			return true;
	if(i>1000)
		if(h[i%10]&&h[(i/10)%10]&&h[(i/100)%10]&&h[i/1000])
			return true;
	if(i<100)
        if(h[i%10]&&h[i/10])
            return true;
	return false;
}

int main()
{
	ifstream cin("crypt1.in");
	ofstream cout("crypt1.out");
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> in;
		num[i]=in;
		h[in]=true;
	}
	for(int i1=0;i1!=n;i1++)
		for(int i2=0;i2!=n;i2++)
			for(int i3=0;i3!=n;i3++)
				for(int i4=0;i4!=n;i4++)
					for(int i5=0;i5!=n;i5++)
					{
						fp=(num[i1]*100+num[i2]*10+num[i3])*num[i5];
						sp=(num[i1]*100+num[i2]*10+num[i3])*num[i4];
						sum=fp+sp*10;
						if( fp<111 || sp <111 || fp>999||sp>999 ||sum>9999||sum<1111)continue;
						if(find(fp)&&find(sp)&&find(sum))
							ans++;
					}
	cout << ans <<endl;	
	return 0;
}
