/*
* File:        longest.c
* Desciption:  动态规划算法计算网络的最长路线和最短路线
* Created:    2001/12/2
* Author:      Justin Hou [mailto:justin_hou@hotmail.com]
*
*/
#include <stdio.h>
#define  N  7                                              /* 顶点数目    */
#define  I  999                                            /* 表示无穷大  */

int graph[N][N] = {                                        /* 图的邻接矩阵 */
        {I, 4, 5, 8, I, I, I},
        {I, I, I, 6, 6, I, I},
        {I, I, I, 5, I, 7, I},
        {I, I, I, I, 8, 9, 9},
        {I, I, I, I, I, I, 5},
        {I, I, I, I, I, I, 4},
        {I, I, I, I, I, I, I}
};
int List[N];                                                /* 存放拓扑序列 */

int TopologicalOrder();                                    /* 拓扑排序函数 */

void main()                                                /* 主 函 数    */
{
        int i, j, k, l;
        int ee[N], el[N];                                  /* 最长最短距离 */
        int path_e[N][N], path_l[N][N], n_e[N], n_l[N];    /* 记录路径数据 */

        /* 初始化数据 */
        for (i = 0; i < N; i++) {
                n_e[i] = 0;                      /* 到 i 的最短路线的结点数 */
                n_l[i] = 0;                      /* 到 i 的最长路线的结点数 */
                ee[i] = I;
                el[i] = 0;
        }
        ee[0] = el[0] = 0;                                  /* 初始化头结点 */
        path_e[0][0] = 0;
        path_l[0][0] = 0;
        n_e[0] = 1;
        n_l[0] = 1;

        /* 拓扑排序 */
        if (!TopologicalOrder())
                return;

        /* 对于拓扑序列,运用动态规划步步算出最长路线与最短路线 */
        for (i = 0; i < N; i++) {

                /* 提取拓扑序列的元素 */
                k = List[i];
                /* 更新它所指向顶点的所有数据 */
                for (j = 0; j < N; j++) {

                        /* 寻找指向的顶点 */
                        if (graph[k][j] != I) {

                                /* 如果新路径更短 */
                                if (graph[k][j] + ee[k] < ee[j]) {

                                        /* 更新最短路径长度 */
                                        ee[j] = graph[k][j] + ee[k];
                                        /* 更新最短路线 */
                                        for (l = 0; l < n_e[k]; l++) {
                                                path_e[j][l] = path_e[k][l];
                                        }
                                        path_e[j][l] = j;
                                        n_e[j] = l + 1;
                                }

                                /* 如果新路径更长 */
                                if (graph[k][j] + el[k] > el[j]) {

                                        /* 更新最长路径长度 */
                                        el[j] = graph[k][j] + el[k];
                                        /* 更新最长路线 */
                                        for (l = 0; l < n_l[k]; l++) {
                                                path_l[j][l] = path_l[k][l];
                                        }
                                        path_l[j][l] = j;
                                        n_l[j] = l + 1;
                                }
                        }
                }
        }

        /* 输出结果到屏幕 */
        for (i = 0; i < N; i++) {
                printf("shortest(%d): %2d    Path: ", i + 1, ee[i]);
                for (j = 0; j < n_e[i]; j++) {
                        printf("%d ", path_e[i][j] + 1);
                }
                printf("\n");        
                printf("longest (%d): %2d    Path: ", i + 1, el[i]);
                for (j = 0; j < n_l[i]; j++) {
                        printf("%d ", path_l[i][j] + 1);
                }
                printf("\n");
        }
}

int TopologicalOrder()
{
        int i, j, top, count;
        int indegree[N], Stack[N];

        top = 0;                                            /* 栈顶标志    */
        for (i = 0; i < N; i++) {
                indegree[i] = 0;                            /* 初始化入度  */
                for (j = 0; j < N; j++) {
                        if (graph[j][i] != I) {            /* 如连通      */
                                indegree[i]++;              /* 入度自增1    */
                        }
                }
                if (!indegree[i]){                          /* 如入度为零  */
                        Stack[top++] = i;                  /* 入栈        */
                }
        }
        count = 0;                                          /* 输出顶点数  */
        while (top != 0) {
                i = Stack[--top];
                List[count++] = i;
                for (j = 0; j < N; j++) {
                        if (graph[i][j] != I) {            /* 如连通      */
                                if (!(--indegree[j])) {    /* 而且入度为零 */
                                        Stack[top++] = j;  /* 入栈        */
                                }
                        }
                }/* for */
        }/* while */

        return (count < N) ? 0 : 1;
}
