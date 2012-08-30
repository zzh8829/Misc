#include <stdio.h>
#include <windows.h> //windows header

int main()
{
        //得到句柄
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE); 

        //保存原始颜色
    WORD wOldColor; 
    CONSOLE_SCREEN_BUFFER_INFO info; 
    GetConsoleScreenBufferInfo(h,&info); 
    wOldColor = info.wAttributes; 
    
        //设置新颜色
    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf( "This is a RED\n");
    SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf( "This is a GREEN\n");
    SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf( "This is a BLUE\n");

        //还原旧颜色
    SetConsoleTextAttribute(h,wOldColor);
    
    system("pause");
    return 0;
}
