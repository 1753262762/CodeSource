#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
#define re register
struct node
{
    int cnt;
    node *next[26];
    node() : cnt(0)
    {
        fill(next, next + 26, nullptr);
    }
} *root;

void input(char *ss)
{
    int len = strlen(ss);
    node *now = root;
    for (re int i = 0; i < len; ++i)
    {
        node *Next = now->next[ss[i] - 'a'];
        if (Next == nullptr)
        {
            Next = new node();
            now->next[ss[i] - 'a'] = Next;
        }
        now = Next;
    }
    now->cnt++;
}

int search(char *ss)
{
    int len = strlen(ss);
    node *now = root;
    for (re int i = 0; i < len; ++i)
    {
        node *Next = now->next[ss[i] - 'a'];
        if (Next == nullptr)
        {
            return 0;
        }
        now = Next;
    }
    return now->cnt;
}

int main()
{
    root = new node();
    int n, m;
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        char S[maxn];
        cin >> S;
        input(S);
    }
    cin >> m;
    for (re int i = 1; i <= m; ++i)
    {
        char S[maxn];
        cin >> S;
        int res = search(S);
        if (res == 1)
        {
            cout << "OK" << endl;
            input(S);
        }
        else if (res == 0)
        {
            cout << "WRONG" << endl;
        }
        else
            cout << "REPEAT" << endl;
    }
    return 0;
}
