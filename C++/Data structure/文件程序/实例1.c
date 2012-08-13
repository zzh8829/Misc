#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *fp;
    char ch,filename[10];
    scanf("%s",filename);
    if( (fp=fopen(filename,"w") )==NULL)
    {
    	printf("cannot open file\n");
    	exit(0);
    }
    ch=getchar();  /*此语句用来接收在执行scanf语句时最后输入的回车符*/
    ch=getchar();  /*接收输入的第一个字符*/
    while(ch != '#')
    {
    	fputc(ch,fp);putchar(ch);
    	ch=getchar();
    }
    fclose(fp);
}
