小字库DIY

这里的方法是把庞大的十六点阵字库（约160kB吧？）中所要用到的几十个汉字的字模提取出来，存成新的一个小字库。这样做的好处是：

1,空间要求小。我下面这个程序得到的xzku.dat只有1kB字节，几乎缩小了160kB。 在工业控制上有时这点空间是致命的。 

2,程序保密，让人不知所云。

3,实现速度快。主要是fseek语句节省时间，但表现出来的速度快了一半多。 



/*MAKE 自造字库 MAKE*/

main()
{FILE *zkfp, *zk1fp;
 unsigned char *s[S_NUMBER];
 int len[S_NUMBER], i, j, m;
 int qu, wei, l;
 long offset;
 int a[ZISHU], number = 0, xn;
  s[0] = "自造小字库显示软件";
  s[1] = "把所用到的汉字字模提取出来重新组成小字库，";
  s[2] = "使用时即可把原字库抛开。";
  s[3] = "愿与各位朋友商榷。";
  s[4] = "欢迎常到松鼠之家来";
  s[5] = "松鼠拜上。";
 zk1fp = fopen("c:\xzku.dat", "wb");
 zkfp = fopen("c:\hzk16", "rb");
 if (zkfp == NULL) {printf("Can't open the cclib");
		  exit(0);
		  }
 for(i = 0; i < s_number; i++)
	{while(*s[i])
		{
		qu = *(s[i]++)-0xa0; 
		wei = *(s[i]++)-0xa0; 
		l = qu*94+wei; 
		for(j = 0; j < number&&a[j] != l; j++); 
		if(j!=number) 
			continue; 
		a[number++] = l; 
		offset = (94l*(qu-1)+(wei-1))*32l;
		fseek(zkfp, offset, SEEK_SET); 
		for(m = 0;m <32;m++) 
			putc(getc(zkfp), zk1fp);  
		}
	}
 fclose(zkfp); 
 fclose(zk1fp); 
 printf("\nOK!\n");
 } 
 
这仅仅是做小字库的程序。显示的程序只要根据这个思路，就能做出来。主要就是用“for(j=0;j < number&&a[j]!=l;j++);”来控制不要有重复的字模。 技巧在于控制两段程序汉字出现的顺序。