#include <iostream>
#include <cstdio>
using namespace std;
int num[51];
int main()
{
	int n;
	cin >> n;
	for(int t=0;t!=n;t++)
	{
		char in[51];
		scanf("%s",in);
		cout << in <<endl;
		int len = strlen(in);
		for(int i=0;i!=len;i++)
		num[i] = in[i]-'0';
		while(len>2)
		{
			int i=len-1;
			num[i-1]-=num[i];
			while( i>0 && num[i-1]<0 )
			{
				--i;
				num[i]+=10;
				num[i-1]--;
			}
			--len;
			if(num[0]==0)
			{
				for(int j=1;j!=len;j++)
				num[j-1]=num[j];
				--len;
			}
			for(int i=0;i!=len;i++)
			cout << num[i];
			cout <<endl;
		}
		string ok="";
		if(num[0]!=num[1])
		ok="not ";
		cout << "The number " << in <<" is " + ok +"divisible by 11.\n\n";
	}
	system("pause");
	return 0;
}
