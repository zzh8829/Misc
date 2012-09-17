 #include<stdio.h> 
#define MAX 20    /* the max size of a[] and stack.serial[] */ 
#define OVER 0 
#define OK 1 
struct 
{ 
int serial[MAX]; 
int i; 
}stack; 
int weight,a[MAX]; 
void put(int serial) 
{ 
if(stack.i<MAX-1)stack.serial[++stack.i]=serial; 
else printf("The stack is full!\n"); 
} 
int seek(int num) 
{ 
int p; 
if(a[num]==0)return(OVER); 
else{ 
weight-=a[num]; 
if(weight>0) 
{ 
p=seek(num+1); 
if(p==OK){ 
put(num); 
return(OK); 
} 
else{ 
weight+=a[num]; 
p=seek(num+1); 
if(p==OK)return(OK); 
else return(OVER); 
   } 
} 
if(weight==0){put(num);return(OK);} 
if(weight<0) 
{ 
weight+=a[num]; 
p=seek(num+1); 
if(p==OK)return(OK); 
else return(OVER); 
} 

    } 


} 
main() 
{ 
int temp=0; 
stack.i=-1; 
printf("\nPlease input the total wieght you need:"); 
scanf("%d",&weight); 
printf("Please input the weight of little case(Input '0' to end):"); 
do 
scanf("%d",&a[temp]); 
while(a[temp++]!=0); 
/* printf("\t%d",weight); 
for(temp=0;a[temp]!=0;temp++)printf("\t%d",a[temp]); */ 
temp=seek(0); 
if(temp==OK)printf("Complete\n"); 
else printf("Uncomlete\n"); 
for(;stack.i!=-1;stack.i--){ 
temp=stack.serial[stack.i]; 
printf("\t%d",a[temp]); 
} 
} 

 