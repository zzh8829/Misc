/*10个小孩分糖果sweer[10]*/
#include <stdio.h>
int j=0;
main()
{
static int sweet[10]={10,2,8,22,16,4,10,6,14,20};//初始化数组
int i,t[10],l;
printf("               child\n");
printf("round  1   2   3   4   5   6   7   8   9   10 \n");
printf("------------------------------------------------\n");
print(sweet);
while(judge(sweet))
{
for(i=0;i<10;i++)
  if(sweet[i]%2==0)
    t[i]=sweet[i]=sweet[i]/2;      //为偶数时直接分出一半
  else
    t[i]=sweet[i]=(sweet[i]+1)/2;  //为奇数是加1后再分出一半
  for(l=0;l<9;l++)
    sweet[l+1]=sweet[l+1]+t[l];
  sweet[0]+=t[9];
  print(sweet);
}
}

judge(c)
  int c[];
{
int i;
  for(i=0;i<10;i++)
    if(c[0]!=c[i])return(1);
  return(0);
}

print(s)
  int s[];
{
int k;
printf(" %2d ",j++);
for(k=0;k<10;k++)
  printf("%4d",s[k]);
printf("\n");
}