/*另一种求二进制算法*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main(){
double a,d,b=0;        /* d is a decimal,b is the change result,binary*/
int i;
printf("please input the decimal to change:\n");
scanf("%f",&d);
a=d;                /*d to a*/
for(i=0;a>=1;i++){
    if(pow(2,i)>a){
        a=a-pow(2,i-1);
        b=b+pow(10,i-1);
        i=0;
        }
    }
for(i=-1;a>0.000000001;i--){
    if(pow(2,i)<=a){
        a=a-pow(2,i);
        b=b+pow(10,i);
        }
    }
printf("\n the changed result of %f is %f\n",d,b);
} 
 