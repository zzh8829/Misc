#include <iostream>
#include <cstdio>

using namespace std;

bool m[22][22];
int a,b,c,d,n;

int main()
{
	enum Direction {R,D,L,U};
	cin >> b >> a>> d >>c>>n;
	for(int i=1;i<=c;i++)
	for(int j=1;j<=d;j++)
	{
		m[i][j] = 1;
		m[a-c+i][j] = 1;
		m[i][b-d+j] = 1;
		m[a-c+i][b-d+j] = 1;
	}
	for(int i=0;i<=a+1;i++)
	for(int j=0;j<=b+1;j++)
	{
		if(i==0||i==a+1||j==0||j==b+1)
		m[i][j]=1;
	}
	Direction Dir;
	Dir = R;
	int row = 1,col = d+1;
	while(n!=0)
	{
		if (m[row-1][col] && m[row+1][col] && m[row][col+1] && m[row][col-1])
			break;
		m[row][col] = 1;
		if(Dir == R)
		{
			if( !m[row-1][col] )
			{
				Dir = U;
				continue;
			}
			if( !m[row][col+1] )
				col++;
			else
			{
				Dir = D;
				continue;
			}
		}
		else if(Dir == D)
		{
			if( !m[row][col+1] )
			{
				Dir = R;
				continue;
			}
			if( !m[row+1][col] )
				row++;
			else
			{
				Dir = L;
				continue;
			}
		}
		else if(Dir == L)
		{
			if( !m[row+1][col] )
			{
				Dir = D;
				continue;
			}
			if(!m[row][col-1] )
				col--;
			else
			{
				Dir = U;
				continue;
			}
		}
		else if(Dir == U)
		{
			if(!m[row][col-1])
			{
				Dir = L;
				continue;
			}
			if(!m[row-1][col])
				row--;
			else
			{
				Dir = R;
				continue;
			}
		}
		n--;
	}
	cout << col << endl <<row <<endl;
	system("pause");
	return 0;
}
