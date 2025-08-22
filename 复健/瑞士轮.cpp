#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
#define re register

struct node
{
    int power, score, id;
    bool operator<(const node &x) const
    {
        return x.score > this->score;
    }
    void output()
    {
        cout << power << ' ' << score << endl;
    }
} x[maxn];

int main()
{
    freopen("a.in", "r", stdin);
    int n, m, ask;
    cin >> n >> m >> ask;
    for (re int i = 1; i <= n * 2; ++i)
    {
        cin >> x[i].score;
        x[i].id = i;
    }
    for (re int i = 1; i <= n * 2; ++i)
    {
        cin >> x[i].power;
    }
    priority_queue<node> Q;
    for (re int i = 1; i <= n * 2; ++i)
    {
        Q.push(x[i]);
    }
    for (re int i = 1; i <= m; ++i)
    {
        for (re int j = 1; j <= n; ++j)
        {
            node one, two;
            one = Q.top(), Q.pop();
            two = Q.top(), Q.pop();
            if (one.power > two.power)
                ++(one.score);
            else
                ++(two.score);
            x[j] = one;
            x[j * 2] = two;
        }
        for (re int i = 1; i <= n * 2; ++i)
        {
            Q.push(x[i]);
        }
    }
    for (re int i = 1; i <= n * 2; ++i)
    {
        cout << Q.top().id << ' ' << Q.top().score << endl;
        Q.pop();
    }
    // cout << Q.top().id << endl;
    return 0;
}