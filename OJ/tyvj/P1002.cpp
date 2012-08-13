#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name,maxname;
	int N,qm,bj;
	char gb,xb;
	int lw;
	int sum=0,max=0;
	cin >>N;
	for(int i=0;i!=N;i++)
	{
		int j=0;
		cin >>name>> qm>>bj>>gb>>xb>>lw;
		if(qm>80 && lw>=1)
		j+=8000;
		if(qm>85 && bj>80)
		j+=4000;
		if(qm>90)
		j+=2000;
		if(qm>85 && xb == 'Y')
		j+=1000;
		if(bj>80 && gb =='Y')
		j+=850;
		
		if(j>max)
		{
			max=j;
			maxname=name;
		}
		sum+=j;
	}
	cout << maxname <<endl << max << endl << sum <<endl;
	system("pause");
	return 0;
}
