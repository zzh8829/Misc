#include <stdio.h>

//--------------------------------------------------------
// 打印搬运动作
//--------------------------------------------------------
int MoveIt(int x,int Source,int Target)
{
    printf("Move %d From %d to %d\n",x,Source,Target);
    return 0;
}

//--------------------------------------------------------
// 用 4 根柱子移动盘子
// n 是盘子个数，编号从1 到 n
// First 是源柱子号
// Second Third 是两根过渡柱
// Fourth 是目标柱
//--------------------------------------------------------
int MoveHanoi(int n,int First,int Second,int Third,int Fourth)
{
    if (n<1) return 0;                  // 如果没有盘子就返回
    if (n==1)                            // 如果只有一个盘子
    {
        MoveIt(n,First,Fourth);          // 就直接从源柱子移到目标柱子上
        return 0;
    }
    if (n==2)                            // 如果有两个盘子
    {
        MoveIt(n-1,First,Second);        // 把上面的那片移到一个过渡柱上
        MoveIt(n,First,Fourth);          // 把下面的那片移到目标柱上
        MoveIt(n-1,Second,Fourth);      // 再把第 1 片从过渡柱移到目标柱上
return 0;
    }
    if (n==3)                            // 如果有 3 片盘子
    {
        MoveIt(n-2,First,Second);        // 把最小的盘子移到一个过渡柱上
        MoveIt(n-1,First,Third);        // 把中间盘子移到另一过渡柱上
        MoveIt(n,First,Fourth);          // 把最大的盘子移到目标柱上
        MoveIt(n-1,Third,Fourth);        // 把中间盘子移到目标柱上
        MoveIt(n-2,Second,Fourth);      // 把最小的盘子移到目标柱上
        return 0;
    }
                                        // 递归地把上面 n-2 盘子移到一个过渡柱上
                                        // 留下最大的两个盘子
    MoveHanoi(n-2,First,Third,Fourth,Second);
    MoveIt(n-1,First,Third);            // 把倒数第 2 个盘子移到另一个过渡柱上
    MoveIt(n,First,Fourth);              // 把最底下的盘子移到目标柱上
    MoveIt(n-1,Third,Fourth);            // 把倒数第 2 个盘子移到目标柱上
                                        // 递归地把 n-2 个盘子从过渡柱上移到目标柱上
    MoveHanoi(n-2,Second,First,Third,Fourth);
    return 0;
}

int main()
{
    MoveHanoi(4,1,2,3,4);
    return 0;
}
