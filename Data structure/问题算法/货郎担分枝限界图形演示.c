/*
* File: tsp.c
* Description: 求解货郎担问题的分枝限界算法图形演示
*          Branch-and-bound algorithm to solve the
*            travelling salesman problem. CG demo.
* Use:    tcc tsp graphics.lib
* Created: 2001/11/29 - 2001/12/01
* Author: Justin Hou [mailto:justin_hou@hotmail.com]
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

#define  MAX_CITIES  15                                /* 城市的数目      */
#define  INFINITY    9999                              /* 表示无穷大      */
#define  I          INFINITY                          /* 表示无穷大      */

typedef struct _POINT {                                /* 定义点的结构    */
        int x;
        int y;
} POINT;

typedef struct _EDGE {                                /* 定义边的结构    */
        int head;
        int tail;
} EDGE;

typedef struct _PATH {                                /* 定义路径结构    */
        EDGE edge[MAX_CITIES];
        int  edgesNumber;
} PATH;

typedef struct _MATRIX {                              /* 定义花费矩阵结构 */
        int distance[MAX_CITIES][MAX_CITIES];
        int citiesNumber;
} MATRIX;

typedef struct _NODE {                                /* 定义树结点      */
        int bound;                                    /* 结点的花费下界  */
        MATRIX matrix;                                /* 当前花费矩阵    */
        PATH path;                                    /* 已经选定的边    */
} NODE;

int  minDist = INFINITY;
int  GraphDriver;
int  GraphMode;
int  ErrorCode;
POINT city[MAX_CITIES] = {
        {459, 333}, {345, 234}, {362, 245}, {332, 183},
        {323, 343}, {630, 345}, {154, 263}, {213, 112},
        {432, 254}, {534, 223}, {334, 333}, {432, 234},
        { 23, 442}, {600, 400}, {500, 300}
};

int    Simplify(MATRIX *);                    /* 归约矩阵并返回归约常数  */
int    MatrixSize(MATRIX, PATH);              /* 计算矩阵阶数            */
EDGE    SelectBestEdge(MATRIX);                /* 返回最合适的分枝边      */
MATRIX  InitMatrix(void);                      /* 初始化费用矩阵数据      */
MATRIX  LeftNode(MATRIX, EDGE);                /* 计算左枝结点费用矩阵    */
MATRIX  RightNode(MATRIX, EDGE, PATH);        /* 计算右枝结点费用矩阵    */
PATH    AddEdge(EDGE, PATH);                  /* 将边添加到路径数组中    */
PATH    BABA(NODE *);                          /* 分枝回溯函数 B-and-B Ar. */
PATH    MendPath(PATH, MATRIX);                /* 修补没有完成的路径      */
void    ShowMatrix(MATRIX);                    /* 文本显示费用矩阵 调试用  */
void    ShowPath(PATH);                        /* 文本显示路径            */
void    DrawPath(PATH);                        /* 图形显示路径            */

void main()
{
        PATH path;
        NODE root;
        GraphDriver = DETECT;
        initgraph( &GraphDriver, &GraphMode, "" );
        ErrorCode = graphresult();
        if( ErrorCode != grOk ) {
                printf(" Graphics System Error: %s\n",
                      grapherrormsg(ErrorCode));
                exit(1);
        }

        /* 初始化数据，归约，建立根结点 */
        root.matrix = InitMatrix();
        root.bound = Simplify(&(root.matrix));
(root.path).edgesNumber = 0;

        /* 进入搜索循环，最终返回最佳路线 */
        path = BABA(&root);

        /* 显示结果 */
        DrawPath(path);
        ShowPath(path);
        printf("\nminDist:%d\n", minDist);

        getch();
        closegraph();
}

/* 初始化数据 */
MATRIX InitMatrix()
{
        int row, col, n;
        double dx, dy;
        MATRIX c;

        n = MAX_CITIES; /* 有待完善数据读取方式 */
        c.citiesNumber = n;
        for (row = 0; row < n; row++) {
                putpixel(city[row].x, city[row].y, 5);
                for (col = 0; col < n; col++) {
                        dx = (double)(city[row].x - city[col].x);
                        dy = (double)(city[row].y - city[col].y);
                        /* 求两点间距离 */
                        c.distance[row][col] = (int)sqrt(dx * dx + dy * dy);
                        if (row == col)
                                c.distance[row][col] = INFINITY;
                }
        }
        return c;
}
/*
* 算法主搜索函数，Branch-And-Bound Algorithm Search
*            root 是当前的根结点，已归约，数据完善
*/
PATH BABA(NODE* root)
{
        static PATH minPath;
        EDGE selectedEdge;
        NODE *left, *right;

        /* 如果当前矩阵大小为2，说明还有两条边没有选，而这两条边必定只能有一
        * 种组合，才能构成整体回路，所以事实上所有路线已经确定。
        */
        if (MatrixSize(root->matrix, root->path) == 2) {
                if (root->bound < minDist) {
                        minDist = root->bound;
                        minPath = MendPath(root->path, root->matrix);
                        free(root);
                        return (minPath);
                }
        }
        /* 根据左下界尽量大的原则选分枝边 */
        setcolor(7);
        selectedEdge = SelectBestEdge(root->matrix);
        line(city[selectedEdge.head].x, city[selectedEdge.head].y,
                city[selectedEdge.tail].x, city[selectedEdge.tail].y);
        putpixel(city[selectedEdge.head].x, city[selectedEdge.head].y, MAGENTA);
        putpixel(city[selectedEdge.tail].x, city[selectedEdge.tail].y, MAGENTA);

        /*
        * 建立左右分枝结点
        */
        right = (NODE *)malloc(sizeof(NODE));
        if (right == NULL) {
                fprintf(stderr,"Error malloc branch.\n");
                exit(-1);
        }
        /* 使左枝结点站局原根结点位置，节省空间 */
        left = root;
        /* 初始化左右分枝结点 */
        right->matrix = RightNode(root->matrix, selectedEdge, root->path);
        right->bound =        root->bound + Simplify(&(right->matrix));
        right->path = AddEdge(selectedEdge, root->path);

        left->matrix = LeftNode(left->matrix, selectedEdge);
        left->bound = left->bound + Simplify(&(left->matrix));

        /* 如果右结点下界小于当前最佳答案，继续分枝搜索 */
        if (right->bound < minDist) {
                BABA(right);
        }
        /* 否则删除这条不可能产生更佳路线的死枝 */
        else {
                free(right);
        }

        setcolor(BLACK);;
        line(city[selectedEdge.head].x, city[selectedEdge.head].y,
                city[selectedEdge.tail].x, city[selectedEdge.tail].y);
        putpixel(city[selectedEdge.head].x, city[selectedEdge.head].y, MAGENTA);
        putpixel(city[selectedEdge.tail].x, city[selectedEdge.tail].y, MAGENTA);

        /* 如果右结点下界小于当前最佳答案，继续分枝搜索 */
        if (left->bound < minDist) {
                BABA(left);
        }
        /*
        *  如果不是最初根结点才删除，避免'Null pointer assignment'问题
        * ‘Null pointer assingnment'问题指如果手动删除主函数里面的数据
        *  当main()执行完毕后释放空间时找不到数据的指针。
        */
        else if ((left->path).edgesNumber != 0){
                free(left);
        }

        gotoxy(1, 1);
        printf("Current minDist: %d  ", minDist);
        return (minPath);
}

/* 修补路径 */
PATH MendPath(PATH path, MATRIX c)
{
        int row, col;
        EDGE edge;
        int n = c.citiesNumber;

        for (row = 0; row < n; row++) {
                edge.head = row;
                for (col = 0; col < n; col++) {
                        edge.tail = col;
                        if (c.distance[row][col] == 0) {
                                path = AddEdge(edge, path);
                        }
                }
        }
        return path;

}

/* 归约费用矩阵，返回费用矩阵的归约常数 */
int Simplify(MATRIX* c)
{
        int row, col, min_dist, h;
        int n = c->citiesNumber;

        h = 0;
        /* 行归约 */
        for (row = 0; row < n; row++) {
                /* 找出本行最小的元素 */
                min_dist = INFINITY;
                for (col = 0; col < n; col++) {
                        if (c->distance[row][col] < min_dist) {
                                min_dist = c->distance[row][col];
                        }
                }
                /* 如果本行元素都是无穷，说明本行已经被删除 */
                if (min_dist == INFINITY) continue;
                /* 本行每元素减去最小元素 */
                for (col = 0; col < n; col++) {
                        if (c->distance[row][col] != INFINITY) {
                                c->distance[row][col] -= min_dist;
                        }
                }
                /* 计算归约常数 */
                h += min_dist;
        }

        /* 列归约 */
        for (col = 0; col < n; col++) {
                /* 找出本列最小的元素 */
                min_dist = INFINITY;
                for (row = 0; row < n; row++) {
                        if (c->distance[row][col] < min_dist) {
                                min_dist = c->distance[row][col];
                        }
                }
                /* 如果本列元素都是无穷，说明本列已经被删除 */
                if (min_dist == INFINITY) continue;
                /* 本列元素减去最小元素 */
                for (row = 0; row < n; row++) {
                        if (c->distance[row][col] != INFINITY) {
                                c->distance[row][col] -= min_dist;
                        }
                }
                /* 计算归约常数 */
                h += min_dist;
        }
        return (h);
}

/* 搜索所有花费为零的边中最合适的，使左枝下界更大 */
EDGE SelectBestEdge(MATRIX c)
{
        int row, col;
        int n = c.citiesNumber;
        int maxD;
        EDGE best, edge;

        /* 所用函数声明 */
        int D(MATRIX, EDGE);

        maxD = 0;
        for (row = 0; row < n; row++) {
                for (col = 0; col < n; col++) {
                        edge.head = row;
                        edge.tail = col;
                        if (!c.distance[row][col] && maxD < D(c, edge)) {
                                maxD = D(c, edge);
                                best = edge;
                        }
                }
        }
        return (best);
}

/* 计算如果选 edge 作为分枝边，左枝( 不含 edge )下界的增量 */
int D(MATRIX c, EDGE edge)
{
        int row, col, dRow, dCol;
        int n = c.citiesNumber;

        dRow = INFINITY;
        for (col = 0; col < n; col++) {
                if (dRow < c.distance[edge.head][col] && col != edge.tail) {
                        dRow = c.distance[edge.head][col];
                }
        }
        dCol = INFINITY;
        for (row = 0; row < n; row++) {
                if (dCol < c.distance[row][edge.tail] && row != edge.head) {
                        dCol = c.distance[row][edge.tail];
                }
        }
        return (dRow + dCol);
}

/* 删掉所选分枝边( left ) */
MATRIX LeftNode(MATRIX c, EDGE edge)
{
        c.distance[edge.head][edge.tail] = INFINITY;
        return c;
}

/* 删除行列和回路边( right ) */
MATRIX        RightNode(MATRIX c, EDGE edge, PATH path)
{
        int row, col;
        int n = c.citiesNumber;
        EDGE loopEdge;

        /* 声明所需要的求回路边函数 */
        EDGE LoopEdge(PATH, EDGE);

        for (col = 0; col < n; col++)
                c.distance[edge.head][col] = INFINITY;
        for (row = 0; row < n; row++)
                c.distance[row][edge.tail] = INFINITY;

        loopEdge = LoopEdge(path, edge);
        c.distance[loopEdge.head][loopEdge.tail] = INFINITY;

        return (c);
}

/* 计算回路边的函数
* 除了加入的新边， 当前结点路线集合中还可能包含一些已经选定的边， 这些边构成
* 一条或几条路径， 为了不构成回路， 必须使其中包含新边的路径头尾不能相连，本
* 函数返回这个头尾相连的边，以便把这个回路边的长度设成无穷。
*/

EDGE LoopEdge(PATH path, EDGE edge)
{
        int i, j;
        EDGE loopEdge;

        /* 最小的回路边 */
        loopEdge.head = edge.tail;
        loopEdge.tail = edge.head;

        /* 寻找回路边的头端点，即包含新边的路径的尾端点 */
        for (i = 0; i < path.edgesNumber; i++) {
                for (j = 0; j < path.edgesNumber; j++) {
                        if (loopEdge.head == path.edge[j].head) {
                                /* 扩大回路边 */
                                loopEdge.head = path.edge[j].tail;
                                break;
                        }
                }
        }
        /* 寻找回路边的尾端点，即包含新边的路径的头端点 */
        for (i = 0; i < path.edgesNumber; i++) {
                for (j = 0; j < path.edgesNumber; j++) {
                        if (loopEdge.tail == path.edge[j].tail) {
                                /* 扩大回路边 */
                                loopEdge.tail = path.edge[j].head;
                                break;
                        }
                }
        }

        return (loopEdge);
}

/* 将新边加入到路径中 */
PATH AddEdge(EDGE edge, PATH path)
{
        path.edge[path.edgesNumber++] = edge;
        return path;
}


/* 计算花费矩阵当前阶数 */
int MatrixSize(MATRIX c, PATH path)
{
        return (c.citiesNumber - path.edgesNumber);
}

/* 文本方式显示路径 */
void ShowPath(PATH path)
{
        int i;
        EDGE edge;
        int n = path.edgesNumber;

        printf("\nThe path is:\n");
        for (i = 0; i < n; i++) {
                edge = path.edge[i];
                printf("(%d,%d)", edge.head + 1, edge.tail + 1);
        }
}

/* 图形方式显示路径 */
void DrawPath(PATH path)
{
        int i;
        POINT a, b;
        int n = path.edgesNumber;

        for (i = 0; i < n; i++) {
                a.x = city[(path.edge[i]).head].x;
                a.y = city[(path.edge[i]).head].y;
                b.x = city[(path.edge[i]).tail].x;
                b.y = city[(path.edge[i]).tail].y;
                line(a.x, a.y, b.x, b.y);
                setcolor(MAGENTA);
                circle(a.x, a.y, 5);
                circle(b.x, b.y, 5);
                setcolor(BLUE);
        }
}


/* 文本方式显示花费矩阵，调试用 */
void ShowMatrix(MATRIX c)
{
        int row, col;
        int n =  c.citiesNumber;

        for (row = 0; row < n; row++) {
                for (col = 0; col < n; col++) {
                        if (c.distance[row][col] != INFINITY) {
                                printf("%4d", c.distance[row][col]);
                        }
                        else {
                                printf("  -");
                        }
                }
                printf("\n");
        }
}