#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main()
{
    int n,m,i=0,result=0,j=0,tmp,low=1,high=0;
    int *a;
    int *b;
    cin>>n>>m;
    high=n;
    int mid;
    a=(int *)malloc(sizeof(int)*m);
    b=(int *)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a[i],&b[i]); 
    }
    for(i=0;i<m;i++)
    {
        low=1;
        high=n;
        while((high-low)>2)
        {
           mid=(low+high)/2;
           tmp=a[i]*mid-b[i]*(n-mid);
           if(tmp>0)
            {
                 high=mid;      
            }
            else
            {
                 low=mid+1;
            }            
                       
        }
        for(j=low;j<=high;j++)
        {
                 tmp=a[i]*j-b[i]*(n-j);
                 if(tmp>0) 
                 {break;}       
        }     
        if(result==0)
           result=tmp;
        else if(result>tmp)
           result=tmp;
        else
           result=result;
           
    }
    cout<< result<<endl;
   return 0;   
}
