#include <stdio.h>
void main()
{
	int i,j;
	int big[8][8];

   	for (i = 0;i < 8;i++)   /*Ñ­»·Ç¶Ì×*/
      		for (j = 0;j < 8;j++)
         		big[i][j] = i * j; /* ³Ë·¨±í */

   	big[2][6] = 748;
   	big[2][2] = 5;
   	big[5][5] = 177; 

   	for (i = 0;i < 8;i++) 
   	{
      		for (j = 0;j < 8;j++)
         		printf("%5d ",big[i][j]);
      		printf("\n");             
   	}
}