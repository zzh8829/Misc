#include <iostream.h> 
void main() 
{ 
int N, i, j=1, count=0, countTemp=0;  //line 1 
cin >>N; 
for(i=N; i>=-N; i--, j=1, count +=((countTemp-1)*2+1), countTemp=0) 
          //line 2 
{ 
while(countTemp++, (j*(j++)+i*i)<=N*N);  //line 3 
} 
double output = double(count)/double(N*N);  //line 4 
cout.precision(15); 
cout <<output<<endl; 
} 