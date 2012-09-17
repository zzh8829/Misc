#include<stdio.h>
#include<bios.h>

int specialkey(int key[]);

main()
{
  int key[2]={0,0};
  printf("É¨ÃèÂë  ASC¢òÂë\n");
  for(;;)
    {
      specialkey(key);
      if(key[0]||key[1])
	{
	  printf("  %d      ",key[0]);
	  printf("%d \n",key[1]);
	  if(key[0]==1)exit(1);
	}
    }
}

specialkey(int key[2])
{
  if(bioskey(1)){key[0]=0;key[1]=0;return;}
  key[0]=key[1]=bioskey(0);
  key[0]>>=8;
  key[1]&=0xff;
}