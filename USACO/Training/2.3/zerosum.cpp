/*
ID: zzh8829
PROG: zerosum
LANG: C++
*/
//#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream cin("zerosum.in");
ofstream cout("zerosum.out");

int n,e[10]={1,2,3,4,5,6,7,8,9};

void dfs(int s,int sum,int num,int sign,string str)
{
	if(s==n)
	{
		if(sum+sign*num==0)
		cout << str << endl;
		return;
	}
	dfs(s+1,sum,num*10+e[s],sign,str+" "+char(e[s]+'0'));
	dfs(s+1,sum+sign*num,e[s],1,str+"+"+char(e[s]+'0'));
	dfs(s+1,sum+sign*num,e[s],-1,str+"-"+char(e[s]+'0'));	
}
int main()
{
	cin >> n;	
	dfs(1,0,1,1,"1");	
	return 0;
}
