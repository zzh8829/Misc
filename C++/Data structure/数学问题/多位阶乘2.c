#include <stdio.h>

main()
{
  int data[40];
  int digit;
  int i,j,r,k;
  int n;

  for(i=1;i<=40;i++)  /* 将数组初始值设为0 */
    data[i]=0;

  data[0]=1;
  data[1]=1;
  digit=1;

  printf("Enter a number what you want to calculus : ");
  scanf("%d",&n);

  for(i=1;i<=n;i++)
  {
      for(j=1;j<=digit;j++) /* 每位上等乘上阶数 digit 决定有几位*/
	data[j]*=i;
      for(j=1;j<=digit;j++)
      {
	  if(data[j]>10)
	  {
	      for(r=1;r<=digit;r++)
	      {
		  if(data[digit]>10)
		    digit++;
		  data[r+1]+=data[r]/10;
		  data[r]=data[r]%10;
	      }
	  }
      }
      printf("%d!=",i);
      for(k=digit;k>0;k--)
	printf("%d",data[k]);
      printf("\n");
  }
  getch();
}




