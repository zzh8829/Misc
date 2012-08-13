#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h> 

#define h 5  // height 
#define w 5  // width 

void main ()  
{ 
    int a[h][w]; 
    int d=0, direct[4][2]= {{0,1},{1,0},{0,-1},{-1,0}}; 
    int x=0, y=0, i; 
    int x1,y1; 
    memset(a, 0, sizeof(a)); 
    for (i=1; i<= h * w; i++) 
{ 
a[y][x]= i; 
// next postion 
x1= x + direct[d][0]; 
y1= y + direct[d][1]; 
// try next postion 
if (x1 <0|| x1 >=w || y1 <0 || y1 >=h ||a[y1][x1]!=0) 
        { 
            // change direct 
            d = (d + 1) % 4; 
            x1= x + direct[d][0]; 
            y1= y + direct[d][1]; 
        } 
        x= x1; 
        y= y1; 
    } 
    
    // display array 
    for (y= 0; y<h; y++) { 
for (x= 0; x<w; x++) 
printf("%4d", a[y][x]); 
printf("\n"); 
} 
getch(); 
return; 
} 