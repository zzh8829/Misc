/*回文：回文就是正读反读都一样的字符串，
例如："radar","able was i ere i saw elba"和"a man a plan a canal panama"(如果忽略空格）。
请编写递归函数testPalindrome,在数组中的字符串为回文时返回true，否则返回false。
函数忽略字符串中的空格和标点符号。 */

#include <stdio.h>
/*	  字符串   一半数  总个数*/
int charf(char d[],int k,  int i)
{
  if(d[k]==d[i-k]&&k==0)
    return(1);
  else if(d[k]==d[i-k])
    charf(d,k-1,i);    /*递归调用*/
  else
    return(0);
}

main()
{
  int i=0,n=0;
  char a,b[20];
  while ((a=getchar())!='\n')
    {
      b[i]=a;
      i++;
    }
  if(i%2==0)
    n=charf(b,(i/2),i-1);
  else
    n=charf(b,(i/2-1),i-1);
  if(n==0) 
    printf("不是回文"); 
  else
    printf("是回文");
  getch();
}