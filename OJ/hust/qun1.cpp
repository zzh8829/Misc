#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void*a,const void*b)
{
	return (*(int*)a-*(int*)b);
}

int main()
{
	int a,b,c,d;
	int DF=1;
	while(cin>>a>>b>>c>>d)
	{
		int num[4]={a,b,c,d};
		qsort(num,4,sizeof(int),compare);
		if(num[0]==0&&num[1]==0)
		continue;
		else if(DF!=1)
		cout <<endl;
		int f=0;
		if(num[0]==0)
		f=num[1];
		else
		f=num[0];
		do{
			if(num[0]==0)
			{
				continue;}
			if(f!=num[0] )
			{f=num[0];
				cout<<endl;}
			cout<< num[0]<< num[1] << num[2] <<num[3]<< " ";
		} while ( next_permutation (num,num+4) );
		DF++;
	}
	//system("pause");
	return 0;
}
