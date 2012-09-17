这是个汉诺塔程序，在调试的时候，输入的数字最好不要大于15，因为每大一个数
所得的结果的步骤都会多一倍。如果你有耐心等待结果的话除外。汉诺塔是在欧洲
流行的一种游戏，有a,b,c三个竿。a竿上有若干个由大到小的圆盘，大的在下面，
小的在上面，b,c都是空杆，请你把a杆上的圆盘都倒到别的杆上，或b或c，在倒盘
的过程中不可以大的压小的，实例程序如下：

#include <stdio.h>
int i=0;
main()
{
	unsigned n;
	printf("Please enter the number of discs: ");
	scanf("%d",&n);
	printf("\tneedle:\ta\t b\t c\n");
	movedisc(n,'a','c','b');
	printf("\t Total: %d\n",i);
	getch();
}
movedisc(n,fromneedle,toneedle,usingneedle)
unsigned n;
char fromneedle,toneedle,usingneedle;
{
	if(n>0)
	{
		movedisc(n-1,fromneedle,usingneedle,toneedle);
		i++;
		switch(fromneedle)
		{
		   case 'a':switch(toneedle)
				 {
		            case 'b':printf("\t[%d]:\t%2d------>%2d\n",i,n,n);
						break;
					case 'c':printf("\t[%d]:\t%2d------------->%2d\n",i,n,n);
						break;
				 }
			   break;
            case 'b':switch(toneedle)
				 {
		            case 'a':printf("\t[%d]:\t%2d<----------%2d\n",i,n,n);
						break;
					case 'c':printf("\t[%d]:\t\t%2d------>%2d\n",i,n,n);
						break;
				 }
			   break;
            case 'c':switch(toneedle)
				 {
		            case 'a':printf("\t[%d]:\t%2d<--------------%2d\n",i,n,n);
						break;
					case 'b':printf("\t[%d]:\t\t%2d<--------%2d\n",i,n,n);
						break;
				 }
			   break;
		}
        movedisc(n-1,usingneedle,toneedle,fromneedle);
	}
}