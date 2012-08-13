#include <iostream>
using namespace std;
int A,B,fieldn=0;

void out(int field[101][101])
{
	for(int i=0;i!=A;i++)
	{
		for(int j=0;j!=B;j++)
		{
			if(field[i][j]==-1)
			cout << "*" ;
			else
			cout << field[i][j];
		}
		cout << endl;
	}
}

void slove(int field[101][101])
{
	for(int i=0;i!=A;i++)
		for(int j=0;j!=B;j++)
			if(field[i][j]==-1)
			{
			if(i!=0 && field[i-1][j]!=-1 )
                   field[i-1][j]++;
			if(i!=A-1 && field[i+1][j]!=-1)
				field[i+1][j]++;
			if(j!=0 && field[i][j-1]!=-1)
				field[i][j-1]++;
			if(j!=B-1 && field[i][j+1]!=-1)
				field[i][j+1]++;
			if(i!=0 && j!=0 && field[i-1][j-1]!=-1)
				field[i-1][j-1]++;
			if(i!=A-1&&j!=B-1 && field[i+1][j+1]!=-1)
				field[i+1][j+1]++;
			if(i!=0 && j!=B-1 && field[i-1][j+1]!=-1)
				field[i-1][j+1]++;
			if(i!=A-1&&B!=0 && field[i+1][j-1]!=-1)
				field[i+1][j-1]++;
			}
	out(field);
}

int main()
{
    bool f=false;
	while(cin >> A >> B )
	{
              if(A==0||B==0)
            break;
        if(f)
         cout <<endl;
        f=true;
        fieldn++;
        cout << "Field #"<< fieldn <<":"<<endl;
		
		int field[101][101];
		for(int i=0;i!=A;i++)
		for(int j=0;j!=B;j++)
		{
            char inc;
			cin >> inc;
			if(inc == '*')
            field[i][j]=-1;
            else
			field[i][j]=0;
		}
		slove(field);
	}
	return 0;
}
