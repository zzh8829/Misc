#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define n 6 
#define m 2*n-1 
typedef struct 
{ float weight; 
 int lchild,rchild,parent; 
}codenode; 
typedef codenode huffmantree[m]; 
typedef struct 
{ char ch; 
 char bits[n+1]; 
}code; 
typedef code huffmancode[n]; 
void inithf(huffmantree T)          //£­¹ş·òÂüÊ÷µÄ³õÊ¼»¯ 
{ int i; 
 for(i=0;i<m;i++) 
  { T[i].weight=0; 
    T[i].parent=-1; 
    T[i].lchild=-1; 
    T[i].rchild=-1; 
  } 
} 
void inputhf(huffmantree T)      //£­ÊäÈë¹ş·òÂüÊ÷µÄÊ÷¾İ 
{ int i;float k; 
 for(i=0;i<n;i++) 
  { scanf("%f",&k); 
    T[i].weight=k; 
  } 
} 
void selectmin(huffmantree T,int k,int *p1,int *p2) 
{ int i;float small1=10000,small2=10000; 
 for(i=0;i<=k;i++) 
  { if(T[i].parent==-1) 
if(T[i].weight<small1) 
  { small2=small1; 
    small1=T[i].weight; 
    *p2=*p1; 
    *p1=i; 
  } 
else 
   if(T[i].weight<small2) 
      { small2=T[i].weight; 
*p2=i; 
      } 
  } 
} 
void creathftree(huffmantree T)    //£­½¨¹ş·òÂüÊ÷ 
{ int i,p1,p2; 
 inithf(T); 
 inputhf(T); 
 for(i=n;i<m;i++) 
  { selectmin(T,i-1,&p1,&p2); 
    T[p1].parent=T[p2].parent=i; 
    T[i].lchild=p1; 
    T[i].rchild=p2; 
    T[i].weight=T[p1].weight+T[p2].weight; 
  } 
} 
void creathfcode(huffmantree T, huffmancode H)  //£­¹ş·òÂü±àÂë±í 
{ int i,c,p,start;char cd[n+1]; 
 cd[n]='\0'; 
 for(i=0;i<n;i++) 
  { H[i].ch=getchar(); 
    start=n; 
    c=i; 
    while((p=T[c].parent)>=0) 
     { 
cd[--start]=(T[p].lchild==c)?'0':'1'; 
c=p; 
     } 
    strcpy(H[i].bits,&cd[start]); 
  } 
} 
void zip(huffmancode H,char *ch,char *s)    //£­±àÂë 
{ int j=0;char *p[n]; unsigned int i;
 for(i=0;i<strlen(ch);i++) 
   {  while(ch[i]!=H[j].ch) j++; 
     p[i]=H[j].bits; 
   } 
  strcpy(s,p[0]); 
 for(i=1;i<n;i++) 
    strcat(s,p[i]); 
 puts(s); 
} 
void uzip(huffmancode H,char *s,huffmantree T)  //£­½âÂë 
{ int j=0,p;
  unsigned int i; 
 char ch[n+1]; 
 while(i<strlen(s)) 
  { p=m-1; 
    while(T[p].lchild!=-1) 
     { if(s[  i  ]=='0') 
 { p=T[p].lchild;i++;} 
else 
 { p=T[p].rchild;i++;} 
     } 
    ch[j]=H[p].ch; 
    j++; 
  } 
  ch[j]='\0'; 
 puts(ch); 
} 
main() 
{ char ch[]="abcdef", s[36]; 
 huffmantree T; 
 huffmancode H; 
 creathftree(T); 
 getchar(); 
 creathfcode(T,H); 
 zip(H,ch,s); 
 uzip(H,s,T); 
} 