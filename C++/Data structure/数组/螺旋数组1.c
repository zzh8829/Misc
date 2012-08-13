#include"stdio.h" 
#include"iostream.h" 

int array[11][11]; 
int temp; 
int ROW; 
void godown(int &m,int &a) 
{ 
for(temp=1;temp<=ROW;temp++) 
if(array[temp][a]==0) 
array[temp][a]=m++; 
a++; 
} 
void goright(int &m,int &b) 
{ 
for(temp=1;temp<=ROW;temp++) 
if(array[b ][temp]==0) 
array[b ][temp]=m++; 
b--; 
} 
void goup(int &m,int &c) 
{ 
for(temp=ROW;temp>0;temp--) 
if(array[temp][c]==0) 
array[temp][c]=m++; 
c--; 
} 
void goleft(int &m,int &d) 
{ 
for(temp=ROW;temp>0;temp--) 
if(array[d][temp]==0) 
array[d][temp]=m++; 
d++; 
} 
void main() 
{ 
int a,b,c,d,max,m; 
cout<<"请输入缧旋方阵的维数n(不能大于10):"; 
cin>>ROW; 
cout<<endl; 
for(a=1;a<=ROW;a++) 
for(b=1;b<=ROW;b++) 
array[a][b ]=0; 
m=1; 
a=d=1; 
b=c=ROW; 
max=ROW*ROW; 
while(m<=max) 
{ 
godown(m,a); 
goright(m,b); 
goup(m,c); 
goleft(m,d); 
} 
for(a=1;a<=ROW;a++) 
{ 
for(b=1;b<=ROW;b++) 
printf("%3d ",array[a][b ]); 
cout<<endl; 
} 
} } 