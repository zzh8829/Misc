#include <cstdio>
#include <cstdlib>
using namespace std;

bool winPos[32][32][32][32];
int move[5][4]={
    {2,1,0,2},
    {1,1,1,1},
    {0,0,2,1},
    {0,3,0,0},
    {1,0,0,1}};

int main()
{
    int n,a,b,c,d;
    for(int i=0;i!=31;i++)
    for(int j=0;j!=31;j++)
    for(int k=0;k!=31;k++)
    for(int l=0;l!=31;l++)
    for(int m=0;m!=5;m++)
    if(i-move[m][0]>=0 && j-move[m][1]>=0 && k-move[m][2]>=0 && l-move[m][3]>=0 )
    if(!winPos[i-move[m][0]][j-move[m][1]][ k-move[m][2]][l-move[m][3]])
        winPos[i][j][k][l]= true;
	scanf("%d",&n);
    for(int i=0;i!=n;i++)
    {
      	scanf("%d%d%d%d",&a,&b,&c,&d);
        if(winPos[a][b][c][d])
        	printf("Patrick\n");
        else
            printf("Roland\n");
    }
    system("pause");
    return 0;
}