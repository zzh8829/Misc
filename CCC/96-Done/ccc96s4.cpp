#include <iostream>
#include <string>
using namespace std;

int r[256];
char ri[11];
string ill="CONCORDIA CUM VERITATE";
int rtoi(string a)
{
    int s=0;
    for(int i=0;i!=a.size();i++)
    {
        if( i<a.size()-1 && (a[i]==0 || a[i]!=a[i-1]) && r[a[i]]<r[a[i+1]] )
            s-=r[a[i]];
        else
            s+=r[a[i]];
    }
    return s;
}

string itor(int a)
{
    if(a>1000) return ill;
    string s="";
    int ro[256];
    ro[ri[7]]=a/1000; a-=a/1000*1000;
    ro[ri[6]]=a/500; a-=a/500*500;
    ro[ri[5]]=a/100; a-=a/100*100;
    ro[ri[4]]=a/50; a-=a/50*50;
    ro[ri[3]]=a/10; a-=a/10*10;
    ro[ri[2]]=a/5; a-=a/5*5;
    ro[ri[1]]=a;
    for(int i=1;i<=7;i++)
    {
        if(ro[ri[i]]<4)
            for(int j=0;j<ro[ri[i]];j++)
                s=ri[i]+s;
        else
        {
            int t=i+1;
            while(ro[ri[t]]==1)
            {
                ro[ri[t]]--;
                t++;
            }
            s=ri[t]+s;
            s=ri[i]+s;
        }
    }
    return s;
}

int main()
{
    r['I']=1;r['V']=5;r['X']=10;r['L']=50;
    r['C']=100;r['D']=500;r['M']=1000;
    ri[1]='I';ri[2]='V';ri[3]='X';ri[4]='L';
    ri[5]='C';ri[6]='D';ri[7]='M';
    int n;
    cin >>n;
    cin.ignore();
    for(int cs=0;cs!=n;cs++)
    {
        string in;
        getline(cin,in);
        int plus=in.find('+');
        string a=in.substr(0,plus);
        string b=in.substr(plus+1,in.size()-plus-2);
        cout << in<<itor(rtoi(a)+rtoi(b)) <<endl;
    }
    return 0;
}

