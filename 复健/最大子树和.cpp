#include <bits/stdc++.h>
using namespace std;

#define re register
const int maxn = 16000 + 5;

struct node
{
    int to, next;
} edge[maxn];
int head[maxn], cnt;
void make_edge(int from, int to)
{
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    head[from] = cnt;
}
int val[maxn];
int main()
{
    int n;
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        cin >> val[i];
    }
    for (re int i = 1; i < n; ++i)
    {
        int tmp_from, tmp_to;
        make_edge(tmp_from, tmp_to);
    }

    return 0;
}