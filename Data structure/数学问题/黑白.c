/*有A,B,C,D,E,五人，每人额头上都帖着一张或黑或白的纸。五人对坐，每人都能看见别人的，但看不见自己的。而且黑的撒谎，白的诚实。
A说：“我看见有三个人的是白纸，一人是黑纸”。
B说：“我看见四个人的都是黑纸”。
C说：“我看见有一个人的是白纸，三个人是黑纸”。
D说：“我看见四个人的都是白纸”。
E什么也没有说。*/
#include <stdio.h>
main()
{
	int a,b,c,d,e;
	for(a=0;a<=1;a++)
		for(b=0;b<=1;b++)
			for(c=0;c<=1;c++)
				for(d=0;d<=1;d++)
					for(e=0;e<=1;e++)
						if((a&&b+c+d+e==3||!a&&b+c+d+e!=3)
							&&(b&&a+c+d+e==0||!b&&a+c+d+e!=0)
							&&(c&&a+b+d+e==1||!c&&a+b+d+e!=1)
							&&(d&&a+b+c+e==4||!d&&a+b+c+e!=4))
						{
							printf("A is pasted a piece of %s paper on his forehead.\n",a?"white":"black");

							printf("B is pasted a piece of %s paper on his forehead.\n",b?"white":"black");

							printf("C is pasted a piece of %s paper on his forehead.\n",c?"white":"black");

							printf("D is pasted a piece of %s paper on his forehead.\n",d?"white":"black");
								
							printf("E is pasted a piece of %s paper on his forehead.\n",e?"white":"black");
						}
}