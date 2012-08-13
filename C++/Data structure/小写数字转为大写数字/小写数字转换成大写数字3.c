#include<stdio.h>
void main()
{
double x,y;
char *ch[]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
char *ch1[]={"拾","佰","仟","万","拾","佰","仟","亿"};
char num[256];
long i,n,j,m,y1;
printf("input:");
scanf("%lf",&x);
n=(long)x;/*得整数部分*/
y=x-n;/*得小数部分*/
for(i=0;n!=0;i++)
  {
  num[i]=(char)(n%10);
  n/=10;
  }
m=i;
num[i]='.';
for(y=y*10;(long)((y-(long)y)*10);) /*如果小数位还是有数(非0)循环继续*/
    y*=10;/*小数转化为整数如0.11111转为11111.00...*/
y1=(long)y;
for(i=m+1;y1!=0;i++)
    {num[i]=(char)(y1%10);
      y1=y1/10;}/*取各位上的数字*/
for(n=0;;n++)
  {
    if(num[n]=='.')
      {
      for(j=n-1;j>=0;j--)/*判断是否是万位,亿位..如是再判断是否是0如是就不输出零.*/
          {
          if(m<=5)
            if(m==5&&(int)num[j]==0)
              ;
            else
                printf("%s",ch[(int)num[j]]);/*输出大写壹..*/
          else
            if(m%4==0&&(int)num[j]==0)
                  ;
            else
              printf("%s",ch[(int)num[j]]);
          if(m>=2)
            {printf("%s",ch1[m-2]);/*输出拾佰仟..如有2位就输出拾*/
              m=m--;}
          }
      printf("点");
      break;
      }
  }
  for(i=i-1;num[i]!='.';i--)
    printf("%s",ch[(int)num[i]]);/*输出小数部分*/
}  