#include <iostream>
#include <cstdio>

using namespace std;

int m[101][101];
int dp[101][101];
int r,c;
int d[8] = {-1,0 ,1,0, 0,1};

int main()
{

	while( cin >>r >> c && r!=0)
	{
		char in;
		for(int i=0;i!=r;i++)
		for(int j=0;j!=c;j++)
		{
			cin >> in;
			if( in =='.' ) m[i][j]=0;
			else if( in =='*' ) m[i][j]=-1;
			else m[i][j] = in-'0';
			dp[i][j]=-1;
		}
		dp[r-1][0]= m[r-1][0];
		
		for( int i=r-2;i>=0;i--)
			if(m[i][0] != -1)
				dp[i][0] = dp[i+1][0] + m[i][0];
			else break;
		
		for(int j=1;j!=c;j++)
		for(int i=0;i!=r;i++) if(m[i][j-1]!=-1 && dp[i][j-1]!=-1)
		for(int g=0;g!=2;g++)
		{
			int tm = dp[i][j-1];
			int tx = i;
			while(tx >= 0 && tx< r && m[tx][j]!=-1)
			{
				tm += m[tx][j];
				if(tm>dp[tx][j])
					dp[tx][j]= tm;
				tx+= d[g*2];
			}
		}
		cout << dp[r-1][c-1] <<endl;	
	}
	system("pause");
	return 0;
}
