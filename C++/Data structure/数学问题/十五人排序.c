/*原题： 一寝室有15个人，每天都要三人一行外出散步一次，要在一周
（7天）内 每个人都跟其他14人各散步一次，问每一天应该怎么安排？？ 
要快点想哟！！！！ 都等一会15分钟*/

#include <stdio.h> 
int anpai[7][5][3]; 
int biaozhi[16][16]; 
int i=0,j=0,k=0,a,total=0; 
void huisu() 
{   
if(k==1) 
{   anpai[ i ][j][0]=0;  j--; 
if(j==-1) {  i--; j=4; } 
biaozhi[anpai[ i ][j][2]][anpai[ i ][j][1]]=0; 
biaozhi[anpai[ i ][j][2]][anpai[ i ][j][0]]=0; 
k=2;  a=anpai[ i ][j][k]; anpai[ i ][j][k]=0;  total-=2; 
} 
else if(k==2)  { biaozhi[anpai[ i ][j][1]][anpai[ i ][j][0]]=0; 
                 a=anpai[ i ][j][--k];  anpai[ i ][j][k]=0; total--; 
} 
} 
void main() 
{   
int b,c,t; 
   for(a=1; a<=15&&total<105; a++) 
{   t=0; 
for(b=0; b<=j; b++) 
for(c=0; c<3; c++) 
if(anpai[ i ][ b ][c]==a) {  b=9; break; } 
if(b==10) 
{ 
   while(a==15) huisu(); 
continue; 
} 
   for(b=0; b<k; b++) 
if(biaozhi[a][anpai[ i ][j][ b ]]==1) 
{ 
  while(a==15) { huisu(); t=1; } 
  break; 
} 
if(b<k||t==1) continue; 
if(a==15&&k<2) { while(a==15) huisu();   continue; } 
switch(k) 
{ 
case 0: anpai[ i ][j][k++]=a; total++; break; 
case 1: anpai[ i ][j][k++]=a; total++; 
   biaozhi[a][anpai[ i ][j][0]]=1;  break; 
case 2: anpai[ i ][j][k]=a;   total++; 
   biaozhi[a][anpai[ i ][j][0]]=1; 
biaozhi[a][anpai[ i ][j][1]]=1; 
j++; 
if(total%15==0) { i++; j=0; } 
k=0; a=0; break; 
} 
} 
 for(a=1;a<8; a++)   
 printf("第%d天      ",a); 
     for(j=0; j<5; j++) 
 {   printf("\n"); 
 for(i=0; i<7; i++) 
 { 
if(i>0&&i<7) printf("  "); 
for(k=0; k<3; k++) 
    printf("%-2d ", anpai[ i ][j][k]); 
 } 
 } printf("\n"); 
} 