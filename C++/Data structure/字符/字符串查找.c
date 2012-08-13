#include <iostream.h>
#define MS 20

char a[MS]="whatisit";
char b[MS]="*is*";
int searchStr(char s1[MS],char s2[MS],int p1,int p2);
bool chazhao(char a[MS],char b[MS]);

void main()
{
	int i;
	cout<<chazhao(a,b);
	cin>>i;
}

bool chazhao(char a[MS],char b[MS])
{

    int i;
    i=searchStr(a,b,1,1);
if(i!=0){i=i-strlen(b)+1;cout<<i<<endl;}
}

//从s1中第n个开始查找s2第m个开始 返回s2的末尾在s1中的位置
/*int searchStr(char s1[MS],char s2[MS],int p1)
{
    int i;
for(i=p1
} */
bool cmpStr(char s1[MS],char s2[MS],int p1)
{
int jc=0;
    for(i=1;i<=strlen(s2);i++)
{
    if(s1[i+p1]!=s2[i])jc=1
    if(jc==1)return true;
    else return false;
}
}
/*    int k;
cout<<p1<<" "<<p2<<endl;
if(s2[p2]==NULL)
    return p1;
while(s1[p1]!=NULL)
{
if(s1[p1]==s2[p2])
{
    p1++;p2++;
k=searchStr(s1,s2,p1,p2);
if(k==0)
    return 0;
else
    return k;
}
p1++;
}
return 0;
}*/
