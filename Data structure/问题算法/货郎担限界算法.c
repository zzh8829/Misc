/*
* File: tsp.c
* Description: 求解货郎担问题的分枝限界算法
*              Branch-and-bound algorithm to solve
*                  the travelling salesman problem.
* Created: 2001/11/29
* Author: Justin Hou [mailto:justin_hou@hotmail.com]
*        C.S.Department of Tongji University
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE (1)
#define FALSE (0)

#define MAX_CITIES (10)
#define INFINITY  (999)
#define I INFINITY

typedef int bool;

/* 定义边结构 */
typedef struct _EDGE {
int head;
int tail;
} EDGE;

/* 定义路径结构 */
typedef struct _PATH {
EDGE edge[MAX_CITIES];
int  edgesNumber;
} PATH;

/* 定义花费矩阵结构 */
typedef struct _MATRIX {
int distance[MAX_CITIES][MAX_CITIES];
int citiesNumber;
} MATRIX;

/* 定义树结点 */
typedef struct _NODE {
int bound; /* 相应于本结点的花费下界 */
MATRIX matrix; /* 当前花费矩阵 */
PATH path; /* 已经选定的边 */
struct _NODE* left; /* 左枝 */
struct _NODE* right; /* 右枝 */
} NODE;

int Simplify(MATRIX*);
EDGE SelectBestEdge(MATRIX);
MATRIX LeftNode(MATRIX, EDGE);
MATRIX RightNode(MATRIX, EDGE, PATH);
PATH AddEdge(EDGE, PATH);
PATH BABA(NODE);
PATH MendPath(PATH, MATRIX);
int MatrixSize(MATRIX, PATH);
void ShowMatrix(MATRIX);
void ShowPath(PATH, MATRIX);

main()
{
PATH path;
NODE root = {
0, /* 花费下界 */
{{{I, 1, 2, 7, 5}, /* 花费矩阵 */
  {1, I, 4, 4, 3},
  {2, 4, I, 1, 2},
  {7, 4, 1, I, 3},
  {5, 3, 2, 3, I}}, 5}, /* 城市数目 */
{{0}, 0}, /* 经历过的路径 */
NULL, NULL /* 左枝与右枝 */
};

/* 归约，建立根结点 */
root.bound += Simplify(&root.matrix);
/* 进入搜索循环 */
path = BABA(root);
ShowPath(path, root.matrix);

}

/*
* 算法主搜索函数，Branch-And-Bound Algorithm Search
*            root 是当前的根结点，已归约，数据完善
*/
PATH BABA(NODE root)
{
int i;
static int minDist = INFINITY;
static PATH minPath;
EDGE selectedEdge;
NODE *left, *right;

puts("Current Root:\n------------");
ShowMatrix(root.matrix);
printf("Root Bound:%d\n", root.bound);

/* 如果当前矩阵大小为2，说明还有两条边没有选，而这两条边必定只能有一种组合，
* 才能构成整体回路，所以事实上所有路线已经确定。
*/
if (MatrixSize(root.matrix, root.path) == 2) {
if (root.bound < minDist) {
minDist = root.bound;
minPath = MendPath(root.path, root.matrix);
getch();
return (minPath);
}
}
/* 根据左下界尽量大的原则选分枝边 */
selectedEdge = SelectBestEdge(root.matrix);
printf("Selected Edge:(%d, %d)\n", selectedEdge.head + 1, selectedEdge.tail + 1);

/* 建立左右分枝结点 */
left = (NODE *)malloc(sizeof(NODE));
right = (NODE *)malloc(sizeof(NODE));
if (left == NULL || right == NULL) {
fprintf(stderr,"Error malloc.\n");
exit(-1);
}
/* 初始化左右分枝结点 */
left->bound = root.bound; /* 继承父结点的下界 */
left->matrix = LeftNode(root.matrix, selectedEdge); /* 删掉分枝边 */
left->path = root.path; /* 继承父结点的路径，没有增加新边 */
left->left = NULL;
left->right = NULL;

right->bound = root.bound;
right->matrix = RightNode(root.matrix, selectedEdge, root.path);/* 删除行列和回路边 */
right->path = AddEdge(selectedEdge, root.path); /* 加入所选边 */
right->left = NULL;
right->right = NULL;

/* 归约左右分枝结点 */
left->bound += Simplify(&left->matrix);
right->bound += Simplify(&right->matrix);

/* 链接到根 */
root.left = left;
root.right = right;

/* 显示到监视器 */
puts("Right Branch:\n------------");
ShowMatrix(right->matrix);
puts("Left Branch:\n-----------");
ShowMatrix(left->matrix);

/* 如果右结点下界小于当前最佳答案，继续分枝搜索 */
if (right->bound < minDist) {
BABA(*right);
}
/* 否则不搜索，因为这条枝已经不可能产生更佳路线 */
else {
printf("Current minDist is %d, ", minDist);
printf("Right Branch's Bound(= %d).\n", right->bound);
printf("This branch is dead.\n");
}

/* 如果右结点下界小于当前最佳答案，继续分枝搜索 */
if (left->bound < minDist) {
BABA(*left);
}
/* 否则不搜索，因为这条枝已经不可能产生更佳路线 */
else {
printf("Current minDist is %d, ", minDist);
printf("Left Branch's Bound(= %d).\n", left->bound);
printf("This branch is dead.\n");
}

printf("The best answer now is %d\n", minDist);
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

/* 计算如果选 edge 作为分枝边，左枝（不含 edge）下界的增量 */
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

/* 删掉所选分枝边 */
MATRIX LeftNode(MATRIX c, EDGE edge)
{
c.distance[edge.head][edge.tail] = INFINITY;
return c;
}

/* 删除行列和回路边后的矩阵 */
MATRIX RightNode(MATRIX c, EDGE edge, PATH path)
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
* 除了加入的新边， 当前结点路线集合中还可能包含一些已经选定的边， 这些边构成一条或
* 几条路径， 为了不构成回路， 必须使其中包含新边的路径头尾不能相连，本函数返回这个
* 头尾相连的边，以便把这个回路边的长度设成无穷。
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

/* 显示路径 */
void ShowPath(PATH path, MATRIX c)
{
int i, dist;
EDGE edge;
int n = path.edgesNumber;

dist = 0;
printf("\nThe path is: ");
for (i = 0; i < n; i++) {
edge = path.edge[i];
printf("(%d, %d) ", edge.head + 1, edge.tail + 1);
dist += c.distance[edge.head][edge.tail];
}
/* printf("[Total Cost: %d]\n", dist); */
}

/* 显示花费矩阵 */
void ShowMatrix(MATRIX c)
{
int row, col;
int n =  c.citiesNumber;

for (row = 0; row < n; row++) {
for (col = 0; col < n; col++) {
if (c.distance[row][col] != INFINITY) {
printf("%3d", c.distance[row][col]);
}
else {
printf("  -");
}
}
putchar('\n');
}
getch();
}