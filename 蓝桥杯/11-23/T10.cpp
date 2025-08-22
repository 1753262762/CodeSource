#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
#define re register

struct node
{
    int x, y;
    int flag;
    void output()
    {
        cout << x << ' ' << y << endl;
    }
} x[maxn];
char ss[maxn];
int change_x[5] = {0, 1, 0, -1};
int change_y[5] = {1, 0, -1, 0};
node move(node now, node change, int flag)
{
    node res;
    if (flag == 0)
    {
        res.x = now.x + change.x;
        res.y = now.y + change.y;
    }
    else if (flag == 1)
    {
        res.x = now.x + change.y;
        res.y = now.y - change.x;
    }
    else if (flag == 2)
    {
        res.x = now.x - change.x;
        res.y = now.y - change.y;
    }
    else if (flag == 3)
    {
        res.x = now.x - change.y;
        res.y = now.y + change.x;
    }
    return res;
}
int change_flag_L(int x)
{
    if (x == 0)
        return 3;
    return x - 1;
}
int change_flag_R(int x)
{
    if (x == 3)
        return 0;
    return x + 1;
}
struct cmp
{
    bool operator()(const node &a, const node &b)
    {
        if (a.x != b.x)
            return a.x < b.x;
        if (a.y != b.y)
            return a.y < b.y;
        return a.flag < b.flag;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    node now = {0, 0};
    int flag = 0;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> ss[i];
        if (ss[i] == 'F')
        {
            now = move(now, {1, 0}, flag);
        }
        else if (ss[i] == 'L')
        {
            flag = change_flag_L(flag);
            now = move(now, {1, 0}, flag);
        }
        else if (ss[i] == 'R')
        {
            flag = change_flag_R(flag);
            now = move(now, {1, 0}, flag);
        }
        x[i] = now;
        x[i].flag = flag;
    }
    set<node, cmp> Q;
    int ans = 0;
    for (re int i = 1; i <= n; ++i)
    {
        node before, future;
        before = x[i - 1];
        future.x = x[n].x - x[i].x, future.y = x[n].y - x[i].y;
        node To;
        if (ss[i] == 'F')
        {
            To = move(move(before, {1, 0}, change_flag_L(before.flag)), future, change_flag_L(before.flag));
            To.output();
            if (Q.find(To) != Q.end())
                Q.insert(To), ans++;
            To = move(move(before, {1, 0}, change_flag_R(before.flag)), future, change_flag_R(before.flag));
            To.output();
            if (Q.find(To) != Q.end())
                Q.insert(To), ans++;
        }
        else if (ss[i] == 'L')
        {
            To = move(move(before, {1, 0}, before.flag), future, before.flag);
            To.output();

            if (Q.find(To) != Q.end())
                Q.insert(To), ans++;

            To = move(move(before, {1, 0}, change_flag_R(before.flag)), future, change_flag_R(before.flag));
            To.output();

            if (Q.find(To) != Q.end())
                Q.insert(To), ans++;
        }
        else if (ss[i] == 'R')
        {
            To = move(move(before, {1, 0}, before.flag), future, before.flag);
            To.output();

            if (Q.find(To) != Q.end())
                Q.insert(To), ans++;

            To = move(move(before, {1, 0}, change_flag_L(before.flag)), future, change_flag_L(before.flag));
            To.output();

            if (Q.find(To) != Q.end())
                Q.insert(To), ans++;
        }
    }
    cout << ans << endl;
    return 0;
}