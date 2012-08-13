#include <iostream>
using namespace std;

int foo(int set[21],int k)
{
	int an=0;
	for(int i=0;i!=k;i++)
		an+=set[i];	
	an=an-k+1;
	return an;	
}

int main()
{
    int answer[21];
	int times=0;
	cin>>times;
	for(int run=0;run!=times;run++)
	{
		int k=0;
		cin >> k;
		int set[21]={0};
		int n,cnt=0;
		while(cnt!=k &&cin>> n)  
			{
			set[cnt]=n;
			cnt++;
			}
		answer[run] = foo(set,k);
	}
	for(int i=0;i!=times;i++)
	        cout <<answer[i] <<endl;
	system("pause");
	return 0;
}
