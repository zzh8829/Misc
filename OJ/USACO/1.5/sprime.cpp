/*
ID: zzh8829
PROG: sprime
LANG: C++
*/
#include <fstream>
using namespace std;
int n,table[9][100000],n1(4),n2(0),n3(0),n4(0),n5(0),n6(0),n7(0),n8(0);
ifstream cin("sprime.in");
ofstream cout("sprime.out");

bool prime(int a)
{
	if(a==2)
	return true;
	if(a<2)
	return false;
	for(int i=2;i*i<a+1;i++)
	if(a%i==0)
	{//cout << 'F' ;
	return false;}
	return true;
}

void solve(int n)
{
	table[1][0]=2;
	table[1][1]=3;
	table[1][2]=5;
	table[1][3]=7;
	
	for(int j=0;j!=n1;j++)
	for(int i=1;i!=11;i+=2)
	{
		int tmp=table[1][j]*10+i;
	//	cout << tmp<<" ";
		if(prime(tmp))
		{
			table[2][n2++]=tmp;
		//	cout << tmp;
		}
	}
	
	for(int j=0;j!=n2;j++)
	for(int i=1;i!=11;i+=2)
	{
		int tmp=table[2][j]*10+i;
		if(prime(tmp))
		table[3][n3++]=tmp;
	}
	
	for(int j=0;j!=n3;j++)
	for(int i=1;i!=11;i+=2)
	{
		int tmp=table[3][j]*10+i;
		if(prime(tmp))
		table[4][n4++]=tmp;
	}
	
	for(int j=0;j!=n4;j++)
	for(int i=1;i!=11;i+=2)
	{
		int tmp=table[4][j]*10+i;
		if(prime(tmp))
		table[5][n5++]=tmp;
	}
	
	for(int j=0;j!=n5;j++)
	for(int i=1;i!=11;i+=2)
	{
		int tmp=table[5][j]*10+i;
		if(prime(tmp))
		table[6][n6++]=tmp;
	}
	
	for(int j=0;j!=n6;j++)
	for(int i=1;i!=11;i+=2)
	{
		int tmp=table[6][j]*10+i;
		if(prime(tmp))
		table[7][n7++]=tmp;
	}
	
	for(int j=0;j!=n7;j++)
	for(int i=1;i!=11;i+=2)
	{
		int tmp=table[7][j]*10+i;
		if(prime(tmp))
		table[8][n8++]=tmp;
	}
	switch(n)
	{
	case 1: {cout << "2\n3\n5\n7" <<endl;break;}
	case 2: {
			for(int i=0;i!=n2;i++)
			cout << table[2][i]<<endl;
			break;
		}
	case 3: {
			for(int i=0;i!=n3;i++)
			cout << table[3][i]<<endl;
			break;
		}
	case 4: {
			for(int i=0;i!=n4;i++)
			cout << table[4][i]<<endl;
			break;
		}
	case 5: {
			for(int i=0;i!=n5;i++)
			cout << table[5][i]<<endl;
			break;
		}
	case 6: {
			for(int i=0;i!=n6;i++)
			cout << table[6][i]<<endl;
			break;
		}
	case 7: {
			for(int i=0;i!=n7;i++)
			cout << table[7][i]<<endl;
			break;
		}
	case 8: {
			for(int i=0;i!=n8;i++)
			cout << table[8][i]<<endl;
			break;
		}
	}
}

int main()
{
	cin >> n;
	solve(n);	
	return 0;
}
