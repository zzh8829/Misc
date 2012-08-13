/*本程序能读取系统环境变量,查看有无鼠标.若有,便输出Mouse is OK,
反之便输出No mouse.*/

/********************read mouse***********************/

#include<stdio.h>/*for function of printf()*/
#include<stdlib.h>/*for function of exit()*/
#include<string.h>/*for function of strcmp()*/


void loadmous(void); /*查看有无鼠标子函数*/
/*主函数开始*/
main()
{
    loadmous();
    return 0;
}
/*子函数*/
void loadmous()
{
    char *p;
    if((p=getenv("MOUSE"))!=NULL){/*调用getenv()函数,读取系统环境变量*/
        if(!strcmp(p,"YES"))/*判断有无鼠标*/
        printf("Mouse is OK\n");
    }
    else{
	printf("\n No mouse");
	getch();
	exit(1);/*正常退出程序*/
    }
}