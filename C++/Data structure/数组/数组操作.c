#include <stdio.h>  

void main()
{
   char strg[40],*there,one,two;
   int *pt,list[100],index;

   strcpy(strg,"This is a character string.");

   one = strg[0];                    /* one 和 two是相同的 */
   two = *strg;
   printf("第一输出的是 %c %c\n",one,two);

   one = strg[8];                   
   two = *(strg+8);
   printf("第二输出的是 %c %c\n",one,two);

   there = strg+10;           /* strg+10 等同于 strg[10] */
   printf("第三输出的是 %c\n",strg[10]);
   printf("第四输出的是 %c\n",*there);

   for (index = 0;index < 100;index++)
      list[index] = index + 100;
   pt = list + 27;
   printf("第五输出的是 %d\n",list[27]);
   printf("第六输出的是 %d\n",*pt);
}
