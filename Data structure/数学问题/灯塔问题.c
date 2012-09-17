//灯塔问题
#include <iostream.h>
#include <fstream.h>
#include <conio.h>
int sz[11][11],cf=1,k,n,a[20],b[20],c[20];
void shuru(void);
void shuchu(void);
bool panduan(void);
void goujian(void);
void main()
{
    int i,j,lj=0,d;
    shuru();
for(i=1;i<=n;i++)cf=cf*2;
for(i=0;i<cf;i++)
{
    d=i;
    for(j=1;j<=n;j++)
    {sz[n][n-j+1]=d%2;d=d/2;}
    goujian();
    if(panduan()==true){lj=lj+1;shuchu();}
}
cout<<"共有"<<lj<<"种情况"<<endl;
getch();
}
void goujian(void)
{
    int i1,j1;
    for(i1=n-1;i1>0;i1--)
    {
for(j1=1;j1<=i1;j1++)
{
    if(sz[i1+1][j1]==1&&sz[i1+1][j1]==1)
        sz[i1][j1]=0;
    if(sz[i1+1][j1]==0&&sz[i1+1][j1+1]==0)
        sz[i1][j1]=0;
    if(sz[i1+1][j1]==1&&sz[i1+1][j1+1]==0)
        sz[i1][j1]=1;
    if(sz[i1+1][j1]==0&&sz[i1+1][j1+1]==1)
        sz[i1][j1]=1;
}
}
}
bool panduan()
{
    int pd=1,j1;
for(j1=1;j1<=k;j1++)
    if(sz[a[j1]][b[j1]]!=c[j1]) pd=0;
if(pd==0) return false;else return true;
}
void shuchu(void)
{
    int i2,j2;
for(i2=1;i2<=n;i2++)
{
    for(j2=1;j2<=n-i2;j2++) cout<<" ";
for(j2=1;j2<=i2;j2++) cout<<sz[i2][j2]<<" ";
cout<<endl;
    }
cout<<endl;
}
void shuru(void)
{
//    char filename[18];
ifstream input;
// cout<<"Input filename:";
// cin>>filename;
// input.open(filename);
input.open("dt.txt");
input>>n;
k=0;
do{
    k++;
input>>a[k]>>b[k]>>c[k];
}while((a[k]!=0)&&(b[k]!=0));
k--;
}