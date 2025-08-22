#include <stdio.h>
// 地图数组和visited记录数组
int a[110][110];
int visited[110][110]; // 0代表访问了,1代表未访问

// 细胞计数器
int count = 0;

// 全局判断变量pd(1表示可以进行下一步,0表
// 示不可以)
int pd;
int *t = &pd;

// 结构体-队列
struct queue
{
    int x;
    int y;
} que[10010];
// 全局定义结构体数组queue(队列)n*m最大
// 值为10000,我使用循环队列

// 队列 头元素标记变量front
int front = 1;
// 队列 尾元素标记变量rear
int rear = 1;

// 因为当front=rear时,队列
// 为空或者满,所以额外定义标记tag:记录对队
// 列处理的上一步,以此判断函数是否为空或满
int tag = 0;
/*tag为0表示上一步没有操作或者为出队*/
/*tag为1表示上一步为入队*/

// 判断队列是否为空
static void if_empty()
{
    if (front == rear && tag == 0)
    {
        *t = 0;
        return;
    }
    else
        *t = 1;
    return;
}

// 判断队列是否为满
static void if_full()
{
    if (front == rear && tag == 1) // 满了
    {
        *t = 0;
        return;
    }
    else
        *t = 1;
    return;
}

// 入队
static void input(int input_x, int input_y)
{
    if_full();
    if (pd == 0)
    {
        return;
    }
    else
    {
        visited[input_x][input_y] = 0;
        que[++rear].x = input_x;
        que[++rear].y = input_y;
        tag = 1; // 标记上一步为入列
    }
    if (rear > 10000)
    {
        rear = 1;
    } // 当rear/front的值改变后,检测其是否超过了10000,超过了,就回去0,循环储存
    return;
}

// 出队
static void output()
{
    if_empty();
    if (pd == 0)
    {
        return;
    }
    else
    {
        que[++front].x = 0;
        que[++front].y = 0;
        // 我的结构体队列使用的是全局定义,初始值为0,迷宫数组使用的为1开始的坐标系,不可能令x/y等于1,所以0可以视为出列
        tag = 0; // 标记上一步为出队
    }
    if (front > 10000)
    {
        front = 1;
    }
    return;
}

// 辅助搜索方向数组
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
// BLS主体部分
static void BLS(int x, int y)
{
    // 判断是否已经访问或者为0,访问了或者为a中点为0就直接弹出
    if (visited[x][y] == 0 || a[x][y] == 0)
        return;
    // 储存该点的数值
    que[rear].x = x;
    que[rear].y = y;
    input(x, y);
    printf("(%d,%d)\n", x, y);
    /*入队并储存输入点的x、y值*/
    // visited[x][y] = 0;
    /*标记这个输入的点,已经在入队里面标记了*/
    while (pd == 1)
    {
        // 将队头的位置赋值给x、y,以x和y的为循环中本次的起始点
        x = que[rear].x;
        y = que[rear].y;
        for (int i = 1; i <= 4; i++)
        {

            int mx = x + dx[i];
            int my = y + dy[i];
            printf("%d %d\n", mx, my);
            if (mx < 1 || mx > 100 || my < 1 || my > 100 || visited[mx][my] == 0 || a[mx][my] == 0)
            {
            }
            else
            {
                printf("1");
                input(mx, my);
            }
        }
        output(); // 起始点出队
    }

    count++;

    return;
}

int main()
{
    int n, m;
    scanf_s("%d %d", &n, &m);

    // 初始化n*m的visited"未访问空地",周围是为0的"已访问墙"
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            visited[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf_s("%1d", &a[i][j]); // 只读一位
        }
    }

    // 对每一个地图中的每一个点都进行BLS
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            BLS(i, j);
        }
    }
    printf("%d", count);
    return 0;
}