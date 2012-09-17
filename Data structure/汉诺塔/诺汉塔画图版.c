/*这是我老师编的程序 Andy*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
char dd[10][20],space[20];
int a[11],b[11],c[11];

init()
{
	int i,j;
	for(i=0;i<20-1;i++) space[i]=' ';
	space[i]='\0';
	
	for(i=0;i<10;i++)
	{  for(j=0;j<20-1;j++)dd[i][j]=' ';
	   dd[i][j]='\0';
	   for(j=9-i;j<=9+i;j++)dd[i][j]='a'+i;
	}
	for(i=0;i<10;i++) a[i]=i,b[i]=-1,c[i]=-1;
	
	a[10]=2,b[10]=25,c[10]=50;

	for(i=0;i<10;i++)
	{	gotoxy(a[10],10+i);
		cprintf("%s",dd[i]);
	}
}

move(int *s,int *d)
{    int i,j;
	  for(i=0;s[i]==-1&&i<10;i++);
	  gotoxy(s[10],10+i);
	  cprintf("%s",space);
	  for(j=0;d[j]==-1&&j<10;j++);
	  j--;
	  gotoxy(d[10],10+j);
	  cprintf("%s",dd[s[i]]);
	  d[j]=s[i];s[i]=-1;
	  getche();
}

void hanoi(int n,int *s,int *w,int *d)
{	int i;
	if(n==1)move(s,d);
	else
	{	hanoi(n-1,s,d,w);
		move(s,d);
		hanoi(n-1,w,s,d);
	}
}

main()
{
clrscr();
init();
getche();
hanoi(10,a,b,c);
getche();
}
