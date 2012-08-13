#include<string.h>
#include<ctype.h>

/*插入函数 ccode待插入的字符 anystring被插入的字符串 spos插入到字符串的位置*/
void cinsert(char ccode,char *anystring,int spos)
{
    int p;  
    p=strlen(anystring);  /*字符串的长度*/
    spos=spos<0?0:spos;  /*插入范围*/
    spos=spos>=p?p:spos;
    for(;p>=spos;p--)
        anystring[p+1]=anystring[p]; /*从数组最后那那个元素开始向上加*/
    anystring[spos]=ccode;  /*插入该字符*/
}

/*删除函数 anystring被删除的字符串 spos删除第几个字符*/
void cdelete(char *anystring,int spos)
{
    int p;
    p=strlen(anystring);  /*字符串的长度*/
    if(p>0&&spos>=0&&spos<=p){
        while(spos<p)
        {
            anystring[spos]=anystring[spos+1];
            spos++;
        }
    }
}
