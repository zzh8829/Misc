#include <stdio.h>

int f[11][11] ;
int adjm[121][121];
long fgf;
void creatadjm(void);
void e(int,int,int,int);
void travel(int,int);

int n,m;

int main()
{
    int i,j,k,l;
    printf("Input n:");scanf("%d",&n);
    m=n*n;
    creatadjm();
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++) printf("%2d",adjm[i][j]);
            printf("\n");
    }
    getchar();
    printf("Input i,j:");
    scanf("%d %d",&i,&j);
    l=(i-1)*n+j;
    while ((i>0)||(j>0))
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        f[i][j]=0;
    k=0;

    travel(l,k);
printf("%d\n",fgf);fgf=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) printf("%4d",f[i][j]);
            printf("\n");
    }
    getchar();
    printf("Input i,j:");scanf("%d %d",&i,&j);
    l=(i-1)*n+j;
    }
    return 0;
}

void creatadjm()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) 
            f[i][j]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++) 
            adjm[i][j]=0;

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(f[i][j]==0)
{
            f[i][j]=1;
            if((i+2<=n)&&(j+1<=n)) e(i,j,i+2,j+1);
            if((i+2<=n)&&(j-1>=1)) e(i,j,i+2,j-1);
            if((i-2>=1)&&(j+1<=n)) e(i,j,i-2,j+1);
            if((i-2>=1)&&(j-1>=1)) e(i,j,i-2,j-1);
            if((j+2<=n)&&(i+1<=n)) e(i,j,i+1,j+2);
            if((j+2<=n)&&(i-1>=1)) e(i,j,i-1,j+2);
            if((j-2>=1)&&(i+1<=n)) e(i,j,i+1,j-2);
            if((j-2>=1)&&(i-1>=1)) e(i,j,i-1,j-2);
}
    return;
}

void travel(int p,int r)
{
    int i,j,q;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(f[i][j]>r) f[i][j]=0;
    r=r+1;
    i=((p-1)/n)+1;
    j=((p-1)%n)+1;


    f[i][j]=r;

    fgf++;
//if(r==25)printf("%d\n",p);
/*
printf("i=%d,j=%d,r=%d\n",i,j,r); getchar();
*/

    for(q=1;q<=m;q++)
    {
        i=((q-1)/n)+1;
        j=((q-1)%n)+1;
        if((adjm[p][q]==1)&&(f[i][j]==0)) travel(q,r);
    }
    return;
}

void e(int i1,int j1,int i2,int j2)
{
    adjm[(i1-1)*n+j1][(i2-1)*n+j2]=1;
    adjm[(i2-1)*n+j2][(i1-1)*n+j1]=1;
    return;
}
