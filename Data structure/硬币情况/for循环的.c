#include <stdio.h>

main()
{
	int i,j,k,count=1;
	printf("There are following small exchange plans for i Yuan note :\n");
	for(i=0;i<=100;i++)
		for(j=0;j<=100-i;j+=2)
			for(k=0;k<=100-i-2*j;k+=5)
				if(i+j+k==100)
					printf(count%4? "%d: 1*%d+2*%d+5*%d   ":"%d:1*%d+2*%d+5*%d\n",count++,i,j/2,k/5);
	getch();
}    