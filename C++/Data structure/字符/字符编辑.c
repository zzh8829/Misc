这儿有两个函数,能进行在一个字符串中的插入和删除一个字符,有兴趣的可以参考一下.

  

#include<string.h>
#include<ctype.h>

void cinsert(char ccode,char *anystring,int spos)
{
    int p;
    p=strlen(anystring);
    spos=spos<0?0:spos;
    spos=spos>=p?p:spos;
    for(;p>=spos;p--)
        anystring[p+1]=anystring[p];
    anystring[spos]=ccode;
}

void cdelete(char *anystring,int spos)
{
    int p;
    p=strlen(anystring);
    if(p>0&&spos>=0&&spos<=p){
        while(spos<p){
            anystring[spos]=anystring[spos+1];
            spos++;
        }
    }
}

