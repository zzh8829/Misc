/*
* File:        multi.c
* Description:  矩阵乘法动态规划
* Created:      10:20 2001-12-3
* Author:      Justin Hou [mailto:justin_hou@hotmail.com]
*
*/

#include <stdio.h>
#define  N  7

int middle[N][N];

void Show(int, int);

void main()
{
        int i, j, l, k;
        unsigned long m[N+1][N+1], min;
        int r[N+1] = {10, 20, 50, 1, 100, 4, 20, 2};                            /* 矩阵维数 */

        /* 初始化 */
        for (i = 1; i <= N; i++) {
                m[i][i] = 0;
        }
        /* 每此增量加一 */
        for (l = 1; l < N; l++) {

                /* 对于差值为 l 的两个元素 */
                for (i = 1; i <= N - l; i++) {
                        j = i + l; 

                        /* 求其最小组合方式 */
                        min = m[i][i] + m[i+1][j] + r[i-1] * r[i] * r[j];
                        middle[i][j] = i;
                        for (k = i + 1; k < j; k++) {
                                if (min > m[i][k] + m[k+1][j] + r[i-1] * r[k] * r[j]) {
                                        min = m[i][k] + m[k+1][j] + r[i-1] * r[k] * r[j];
                                        middle[i][j] = k;
                                }
                        }
                        m[i][j] = min;
                }
        }
        printf("M = ");
        Show(1, N);
        printf("\nMultiply Count: %d\n", m[1][N]);
}
                        
void Show(int i, int j)
{
        int k, m;

        if (i == j){
                printf("M%d", i);                              /* 如果下一个是矩阵，输出  */
        }
        else {
                m = middle[i][j];                              /* 分割成左右两组          */
                if (i != m) printf("(");                        /* 如果下一个显示的不是矩阵 */
                Show(i, m);                                    /* 显示左边的内容          */
                if (i != m) printf(")");                        /* 如果上一个显示的不是矩阵 */
                printf(" x ");                                  /* 打印乘法符号            */
                if (m+1 != j) printf("(");                      /* 如果下一个显示的不是矩阵 */
                Show(m + 1, j);                                /* 显示右边的内容          */
                if (m+1 != j) printf(")");                      /* 如果下一个显示的不是矩阵 */
        }

}