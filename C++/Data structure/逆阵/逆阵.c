#include "stdio.h" 
float z[4][4],*y=z;   /*定义一个全局二维数组用来存放N-1阶余子式,因为A的伴随矩阵除以|A|时会产生小数，因此定义成float而非int*/ 

int js(int *p,int n)               /*计算行列式的函数*/ 
{int k=0,i,s2=0,s1=0,j,s,t; 
printf("\n"); 
for(j=0;j<n;j++) 
  { k=j;t=1; 
   for(i=1;i<=n;i++) 
{ t=t*p[k]; 
 if ((k+1)%n==0) k=k+1; 
 else  k=k+n+1; 
} 
   s1=s1+t; 
  } 
for(j=0;j<n;j++) 
   { k=j;t=1; 
     for(i=1;i<=n;i++) 
{ t=t*p[k]; 
  if (k%n==0) k=k+(2*n-1); 
  else k=k+(n-1); 
} 
    s2=s2+t; 
   } 
s=s1-s2; 
return s; 
} 

void n_1(int b[][4])      /*把除第i行j列后的N-1阶矩阵的每个元素赋给一维数组d[]的函数*/ 
{int i,j,e,f,l,m,d[9],*q='\0'; 
int js(int *p,int n); 
printf("\n"); 
for(i=0;i<4;i++) 
   {l=i; 
    for(j=0;j<4;j++) 
{ m=j;q=d; 
 for (e=0;e<4;e++) 
    { if(e==l) continue; 
      for(f=0;f<4;f++) 
 { if(f==m) continue; 
   *q=b[e][f]; 
   q++; 
 } 
    } 
                        /*每得到一个一维数组d[]的值，便调用JS()函数,得到除第i行j列后的N-1阶矩阵的行列式的值,也即是余子式M[j]*/ 
          *(y++)=js(d,3); /*并把余子式的值存放在全局二维数组z[]中*/ 
} 
   } 
} 


prt(int *p,int n) /*矩阵打印函数*/ 
{int i; 
for(i=0;i<n*n;i++) 
    {if(i%n==0) printf("\n"); 
     printf("%4d",p); 
    } 
} 

main() 
{int a[4][4]={1,2,3,4,5,6,7,8,9,9,11,12,13,14,15,16}; 
int m=4,r,i,j,ch; 
 
printf("The old juzhen is:\n"); 
prt(*a,m); 
r=js(*a,m); 
printf("\nThe old juzhen hanglieshi is:|A|==%d",r); 
printf("\nPress Enter continue......"); /*控制屏幕*/ 
ch=getchar(); 
if (r==0) printf("Because |A|==0,the juzhen have no nijuzhen!"); 
else 
    {n_1(a);  /*调用n_1()函数*/ 

     for(i=0;i<m;i++)     /*求代数余子式*/ 
          for(j=0;j<m;j++) 
              if((i+j)%2!=0 && z[i][j]!=0) z[i][j]=-z[i][j]; 
     printf("Because |A|!=0,the juzhen have nijuzhen!\n"); 
     printf("The bansuijuzhen A* is:\n");  /*打印伴随矩阵A* ,i,j对调用于转置*/ 
     for(i=0;i<m;i++) 
         {for(j=0;j<m;j++) 
               if ((i+j)%2==0) printf("%4.0f\t",z[j][i]); 
               else 
           printf("%4.0f\t",z[i][j]); 
          printf("\n"); 
         } 
     printf("\nThe nijuzhen is:(*A)/|A|\n"); 
     for(i=0;i<m;i++)    /*打印A的逆矩阵*/ 
          {for(j=0;j<m;j++) 
if ((i+j)%2==0)  printf("%.3f\t",z[i][j]/r); 
               else 
    printf("%.3f\t",z[j][i]/r); 
           printf("\n"); 
          } 
    } 


}