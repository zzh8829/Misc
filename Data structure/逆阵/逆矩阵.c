#define N 5      /*[注]：修改6为你所要的矩阵阶数*/ 
#include "stdio.h" 
#include "conio.h" 


/*js()函数用于计算行列式,通过递归算法实现*/ 
int js(s,n) 
int s[][N],n; 
{int z,j,k,r,total=0; 
int b[N][N];/*b[N][N]用于存放，在矩阵s[N][N]中元素s[0]的余子式*/ 
if(n>2) {for(z=0;z<n;z++) 
{for(j=0;j<n-1;j++) 
for(k=0;k<n-1;k++) 
if(k>=z) b[j][k]=s[j+1][k+1]; 
else b[j][k]=s[j+1][k]; 
if(z%2==0) r=s[0][z]*js(b,n-1);  /*递归调用*/ 
else  r=(-1)*s[0][z]*js(b,n-1); 
total=total+r; 
} 
} 
else if(n==2) total=s[0][0]*s[1][1]-s[0][1]*s[1][0]; 
return total; 
} 


/*n_1()函数用于求原矩阵各元素对应的余子式，存放在数组b[N][N]中，定义为float型*/ 
void n_1(s,b,n) 
int s[][N],n; 
float b[][N]; 
{int z,j,k,l,m,g,a[N][N]; 
for(z=0;z<n;z++) 
   {l=z; 
    for(j=0;j<n;j++) 
{ m=j; 
 for (k=0;k<n-1;k++) 
      for(g=0;g<n-1;g++) 
 { if(g>=m&&k<l) a[k][g]=s[k][g+1]; 
   else if(k>=l&&g<m)  a[k][g]=s[k+1][g]; 
   else if(k>=l&&g>=m) a[k][g]=s[k+1][g+1]; 
   else a[k][g]=s[k][g]; 
 } 
         b[z][j]=js(a,n-1); 
} 
   } 
} 



main() 
{int a[N][N]; 
float b[N][N]; 
int r,z,j; 
float temp; 
//clrscr(); 
printf("Input original data:\n"); 
for(z=0;z<N;z++)              /*输入所需要的数据，为整型数据*/ 
    for(j=0;j<N;j++) 
scanf("%d",&a[z][j]); 
printf("\nPress Enter continue......"); 
getchar(); 
//gotoxy(1,1); 
printf("The original matrix is:\n"); 
for(z=0;z<N;z++)/*打印原矩阵*/ 
    {for(j=0;j<N;j++) 
 printf("%5d",a[z][j]); 
     printf("\n"); 
    } 
r=js(a,N);                     /*调用js()函数计算原矩阵的行列式值*/ 
printf("\nThe original matrix hanglieshi is:|A|==%d\n",r);     
if (r==0) printf("Because |A|==0,the original matrix have no nijuzhen!");  /*判断条件:若|A|==0，则原矩阵无逆矩阵，反之则存在逆矩阵*/ 
else 
    {n_1(a,b,N);                                       /*调用n_1()函数，得到原矩阵各元素对应的"余子式",存放在数组b[N][N]中*/ 
     for(z=0;z<N;z++)                                  /*求代数余子式，此时b[N][N]中存放的为原矩阵各元素对应的"代数余子式"*/ 
          for(j=0;j<N;j++) 
              if((z+j)%2!=0 && b[z][j]!=0) b[z][j]=-b[z][j]; 
     for(z=0;z<N;z++)        /*对b[N][N]转置,此时b[N][N]中存放的为原矩阵的伴随矩阵*/ 
  for(j=z+2;j<N;j++) 
{temp=b[z][j]; 
b[z][j]=b[j][z]; 
b[j][z]=temp; 
} 
     printf("Because |A|!=0,the original matrix have nijuzhen!\n"); 
     printf("The bansuijuzhen A* is:\n"); 
     for(z=0;z<N;z++)/* 打印伴随矩阵A* */ 
         {for(j=0;j<N;j++) 
              printf("%4.0f\t",b[z][j]); 
          printf("\n"); 
         } 

     for(z=0;z<N;z++)                                  /*求逆矩阵，此时b[N][N]中存放的是原矩阵的逆矩阵*/ 
          for(j=0;j<N;j++) 
b[z][j]=b[z][j]/r; 
     printf("\nThe nijuzhen is:(A*)/|A|(|A|=%d)\n",r);  /*打印逆矩阵*/ 
     for(z=0;z<N;z++) 
    {for(j=0;j<N;j++) 
printf("%8.3f",b[z][j]); 
   printf("\n"); 
  } 
    } 
}
