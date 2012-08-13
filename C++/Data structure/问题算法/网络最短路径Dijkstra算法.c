/*
* File: shortest.c
* Description: 网络中两点最短路径 Dijkstra 算法
*              Shortest Path Dijkstra Algorithm
* Created: 2001/11/25
* Author: Justin Hou [mailto:justin_hou@hotmail.com]
*/

#include <stdio.h>
#define true  1
#define false 0
#define I  9999                                /* 无穷大        */
#define N  20                                  /* 城市顶点的数目 */

int cost[N][N] = {
    {0,3,I,I,I,1,I,I,I,I,I,I,I,I,I,I,I,I,I,I},
    {3,0,5,I,I,I,6,I,I,I,I,I,I,I,I,I,I,I,I,I},
    {I,5,0,4,I,I,I,1,I,I,I,I,I,I,I,I,I,I,I,I},
    {I,I,4,0,2,I,I,I,6,I,I,I,I,I,I,I,I,I,I,I},
    {I,I,I,2,0,I,I,I,I,7,I,I,I,I,I,I,I,I,I,I},
    {1,I,I,I,I,0,1,I,I,I,2,I,I,I,I,I,I,I,I,I},
    {I,6,I,I,I,1,0,6,I,I,I,7,I,I,I,I,I,I,I,I},
    {I,I,1,I,I,I,6,0,2,I,I,I,3,I,I,I,I,I,I,I},
    {I,I,I,6,I,I,I,2,0,8,I,I,I,4,I,I,I,I,I,I},
    {I,I,I,I,7,I,I,I,8,0,I,I,I,I,5,I,I,I,I,I},
    {I,I,I,I,I,2,I,I,I,I,0,4,I,I,I,3,I,I,I,I},
    {I,I,I,I,I,I,7,I,I,I,4,0,3,I,I,I,4,I,I,I},
    {I,I,I,I,I,I,I,3,I,I,I,3,0,3,I,I,I,5,I,I},
    {I,I,I,I,I,I,I,I,4,I,I,I,3,0,7,I,I,I,2,I},
    {I,I,I,I,I,I,I,I,I,5,I,I,I,7,0,I,I,I,I,3},
    {I,I,I,I,I,I,I,I,I,I,3,I,I,I,I,0,5,I,I,I},
    {I,I,I,I,I,I,I,I,I,I,I,4,I,I,I,5,0,8,I,I},
    {I,I,I,I,I,I,I,I,I,I,I,I,5,I,I,I,8,0,6,I},
    {I,I,I,I,I,I,I,I,I,I,I,I,I,2,I,I,I,6,0,4},
    {I,I,I,I,I,I,I,I,I,I,I,I,I,I,3,I,I,I,4,0}
};
int dist[N];                                          /* 存储当前最短路径长度 */
int v0 = 'A' - 65;                                    /* 初始点是 A          */

void main()
{
    int final[N], i, v, w, min;

    /* 初始化最短路径长度数据，所有数据都不是最终数据 */
    for (v = 0; v < N; v++) {
    final[v] = false;
        dist[v] = cost[v0][v];
    }

    /* 首先选v0到v0的距离一定最短，最终数据 */
    final[v0] = true;

    /* 寻找另外 N-1 个结点 */
    for (i = 0; i < N-1; i++) {
        min = I;                                      /* 初始最短长度无穷大  */
        
        /* 寻找最短的边 */
        for (w = 0; w < N; w++) {
            if (!final[w] && dist[w] < min) {
                min = dist[w];
                v = w;
        }
        }
        final[v] = true;                              /* 加入新边          */

        for (w = 0; w < N; w++) {                      /* 更新 dist[] 数据  */
            if (!final[w] && dist[v] + cost[v][w] < dist[w]) {
                dist[w] = dist[v] + cost[v][w];
            }
        }
    }

    for (i = 0; i < N; i++) {                          /* 显示到监视器      */
        printf("%c->%c: %2d\t", v0 + 65, i + 65, dist[i]);
    }
}