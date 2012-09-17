#include <stdio.h>
//#include <stdlib.h>
#define ABS(x) (((x)>0)?(x):(-(x)))
void GetInputValue(float * a,const int howmany)
{
int i=0;
for(i=0;i<howmany;i++)
{
scanf("%f",a);
a++;
}
}
void CalAllPosibility( float * a, float *mmult)
{

int i=0;
int ba[6];

for(i=0;i<0x40;i++)
    {
int k=i;
for(int j=0;j<6;j++)
{

ba[j]=k&0x1;
k=k>>1;

}
mmult[i]=a[0]*ba[0]+a[1]*ba[1]+a[2]*ba[2]+a[3]*ba[3]+a[4]*ba[4]+a[5]*ba[5];


}
            
}
void LookForNearest( float * mmult,const float v)
{
int index=0;
            int i=0;
int ba[6];
            float min=ABS(*mmult-v);

            for(i=0;i<0x40;i++)
{
if(ABS(mmult[i]-10.0)<min)
{
min=ABS(mmult[i]-10.0);
index=i;
}
}


int k=index;
for(int j=0;j<6;j++)
{

ba[j]=k&0x1;
k=k>>1;
//ba++;
}

        printf("result : the nearest value is :%f, %d %d %d %d %d %d",min,ba[0],ba[1],ba[2],ba[3],ba[4],ba[5]);




            
}
main()
{
//仅仅是N=6的情况，更广泛的话，请自行解决。
//define input aray , if u extends this prog , u should dynamic allocate this
float a[6];
//define 中间数组 如果输入数字是N的话，float mult[2^N]
float mult64[64];
      int i=0;

GetInputValue(&a[0],6);
CalAllPosibility(&a[0],&mult64[0]);
    LookForNearest(&mult64[0],10.0);

}