#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define M_A_X 300000
#define  M 4
int graph[M][M];

inline int MIN(int a,int b)
{
	return a<b?a:b;
}
void floyd(int g[M][M],int D[M][M])
{
    for(int k = 0;k<M;k++)
        for(int i = 0;i<M;i++)
        {
            for(int j = 0;j<M;j++)
            {
                if(k == 0)
                    D[i][j] =g[i][j];
                else
                {
                    D[i][j] = MIN(D[i][j],D[i][k]+D[k][j]);
                }
            }
        }
}
void printgraph(int g[M][M],int v)
{
    for(int i = 0;i<v;i++)
    {
        for (int j = 0;j<v;j++)
        {
            if(g[i][j] == M_A_X)
                cout<<"*"<<" ";
            else
                cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int g[M][M]={{0,1,M_A_X,M_A_X},{M_A_X,0,2,M_A_X},{M_A_X,M_A_X,0,3},{4,M_A_X,M_A_X,0}};
    printgraph(g,M);
    floyd(g,graph);
    printgraph(graph,M);
    system("pause");
    return 0;
}
