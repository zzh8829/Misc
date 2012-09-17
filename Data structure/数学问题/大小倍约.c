/*最大公约数，最小公倍数*/

#include <stdio.h>

int hcf(int a,int b)
{
  int r=0;
  while(b!=0)
  {
      r=a%b;
      a=b;
      b=r;
  }
  return(a);
} 

lcd(int u,int v,int h)
{
    return(u*v/h);
}

main()
{
    int u,v,h,l;
    scanf("%d%d",&u,&v);
    h=hcf(u,v);
    printf("H.C.F=%d\n",h);
    l=lcd(u,v,h);
    printf("L.C.D=%d\n",l);
}