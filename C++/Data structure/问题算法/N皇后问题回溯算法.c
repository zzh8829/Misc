/*
* File: queen.c
* Description: 求 N 皇后问题回溯算法
* Created: 2001/11/12
* Author: Justin Hou [mailto:justin_hou@hotmail.com]
*/
#include <stdio.h>

#define  DelayTime  20000                /* 显示棋局时间      */
#define  TopX      10                    /* 棋盘左上角 x 坐标  */
#define  TopY      5                    /* 棋盘左上角 y 坐标  */

int N;                                    /* 皇后数量          */

int a[8], b[15], c[15];
/*
* a[col-1] 记录第 col 列有无皇后, 1 表示有。
* b[row+col-2] 记录从左上数第 row+col-1 条斜率为 1 的线上有无皇后。
* c[row-col+7] 记录从右上数第 row-col+8 条斜率为 -1 的线上有无皇后。
*/
int Num = 0;
int row;  
void BackTrack (int row)
{
    int col;                                        /* 局部变量 */
    for (col=1; col<=N; col++)
    {
        if (a[col-1] + b[row+col-2] + c[row-col+N-1] == 0)
        {
            a[col-1] = 1;                          /* 更改数据 */
            b[row+col-2] = 1;
            c[row-col+N-1] = 1;

            gotoxy(col*2 + TopX, row + TopY);      /* 画皇后  */
            putch('Q');

            if (row < N)
            {
                BackTrack (row + 1);
            }
            else
            {
                Num++;                              /* 递归终点 */
                gotoxy(40, 9);
                printf("Num: %d ", Num);
                delay(DelayTime);
            }

            a[col-1] = 0;                          /* 清空数据 */
            b[row+col-2] = 0;
            c[row-col+N-1] = 0;

            gotoxy(col*2 + TopX, row + TopY);      /* 清除图象 */
putch('.');

        }/* end if */
    }/* end for */
}/* end function BackTrack */

void main()
{
    int i, j;
    clrscr();

    gotoxy(1, 10);                            /* 要求用户输入皇后数量 */
    printf("Input the number of queen: ");
    while(N <= 0 || N > 14)
    {
        scanf("%d", &N);
        if(N > 14) printf("Two huge number, input again:");
        if(N <= 0) printf("Can's smaller than 1, again:");
}

clrscr();

    for(i=1; i<=N; i++)                        /*  画棋盘(Chessboard) */
    {
        for(j=1; j<=N; j++)
        {
            gotoxy(i*2 + TopX, j + TopY);
            putch('.');
        }
    }

    BackTrack(1);                                    /* 开始回溯算法 */

    gotoxy(12, 17);                                  /* 显示最后结果 */
    printf ("There are %d kinds of solution.\n", Num);

    getch();
}