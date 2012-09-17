//#include "graphics.h" 
#include "fcntl.h" 
#include "stdio.h" 
#define  N 30 
int   hzk_p; 
void  open_hzk(void); 
void  get_mat(char hz_code[ ],unsigned char buff[ ]); 
void  creatclib(char *name); 
void  sort( ); 
void  writeclib(char *name); 
unsigned char bytes[32]; 
unsigned *point1[2]; 



struct hz_mat{ 
 unsigned  incode; 
 unsigned  char mat[32]; 
 }; 

 struct hzlib 
 { int n; 
 struct hz_mat lib[N]; 
 }clib; 

 main( ) 
 { 
  open_hzk( ); 
  creatclib("hz.txt"); 
  writeclib("mylib.h"); 
  } 

  void creatclib(char *name ) 
  { 
    register i,j,found,n; 
    FILE *fp; 
    n=0; 
    fp=fopen("li.txt","rt"); 
    rewind(fp); 
    printf("%x  ",fp); 
    if(fp==NULL) 
    { 
     printf("li.txt not exist!ENTER to system"); 
     exit(1); 
     } 
  while(!feof(fp)) 
    { 
    fread(point1,2,1,fp); 
    printf("%x  %x ",*point1,fp); 
    found=0; 
    for(i=0;i<N&&!found;i++) 
{if(clib.lib[i ].incode==*point1) 
found=1; 
      } 
    if(!found) 
{ 
clib.lib[n].incode=*point1; 
      get_mat(point1,bytes); 
      for(j=0;j<32;j++) 
     clib.lib[n].mat[j]=bytes[j]; 
     n++; 
    } 
     } 
   clib.n=n; 
   fclose(fp); 
   sort( ); 
  } 




  void open_hzk( ) 
   { 
   hzk_p=open("c:\\windows\\command\\pdos95.bat",0); 
   printf("%x  ",hzk_p); 
   if(hzk_p==-1) 
   { 
      printf("the hzk 16 not exist!enter to system\n"); 
      getch( ); 
      exit(1); 
      } 
   } 

   void get_mat(char hz_code[ ],unsigned char buff[ ]) 
    { int i; 
    unsigned char qh,wh; 
    unsigned long offset; 
    qh=hz_code[0]-0xa0; 
    wh=hz_code[1]-0xa0; 
    offset=(94*(qh-1)+(wh-1))*32L; 
    lseek(hzk_p,offset,SEEK_SET); 
    read(hzk_p,buff,32); 
    } 

    void writeclib(char *name) 
    { 
FILE *fp; 
int i,j; 
fp=fopen(name,"w"); 
fprintf(fp,"struct hz_mat{\n"); 
fprintf(fp,"unsigned incode;\n"); 
fprintf(fp,"unsigned char mat[32];\n"); 
fprintf(fp,"};\n"); 
fprintf(fp,"struct hzlib{\n"); 
fprintf(fp,"int n;\n"); 
fprintf(fp,"struct hz_mat lib[%d];\n",clib.n); 
fprintf(fp,"}clib={%d,\n{\n",clib.n); 
j=0; 
while(j<clib.n) 
{ 
fprintf(fp,"{0x%x,",clib.lib[j].incode); 
for(i=0;i<32;i++) 
 { 
  fprintf(fp,"0x%x",(unsigned char )clib.lib[j].mat); 
  if(i!=31) 
  fprintf(fp,","); 
  if((i+1)%8==0&&i!=31) 
  fprintf(fp,"\n"); 
  } 
j++; 
if(j!=clib.n) 
  fprintf(fp,"\n"); 
else 
 fprintf(fp,"}\n"); 
 } 
fprintf(fp,"}\n};\n"); 
fclose(fp); 
} 



   void sort(void) 
   { 
    register int a,b,i,m; 
    unsigned t; 
    char buffer[32]; 
    m=clib.n; 
    for(a=1;a<m;++a) 
     for(b=m-1;b>=a;--b) 
      { 
if(clib.lib[b-1].incode>clib.lib[b ].incode) 
 {t=clib.lib[b-1].incode; 
 clib.lib[b-1].incode=clib.lib[b ].incode; 
 clib.lib[b ].incode=t; 
 for(i=0;i<32;i++) 
  { buffer[i ]=clib.lib[b-1].mat[ i]; 
  clib.lib[b-1].mat[i ]=clib.lib[b ].mat[i ]; 
  clib.lib[b ].mat[i ]=buffer[i ]; 
  } 
} 
      } 
      } 