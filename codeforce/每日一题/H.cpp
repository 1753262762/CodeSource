#include <bits/stdc++.h>
using namespace std;

#define re register
struct node
{
    int val;
    node *next;
    node *front;
    node()
    {
        val = 0, next = nullptr;
        front = nullptr;
    }
} *head;
void add(int val)
{
    if (head == nullptr)
    {
        head = new (node);
        head->val = val;
        return;
    }
    node *it = head;
    while (it->next != nullptr)
    {
        it = it->next;
    }
    it->next = new (node);
    it->next->val = val;
    it->next->front = it;
    return;
}
void output()
{
    node *it;
    for (it = head; it != nullptr; it = it->next)
    {
        cout << it->val << ' ';
    }
    cout << endl;
    return;
}
void del(node *it)
{
    if (it == head)
    {
        head = it->next;
        free(it);
        return;
    }
    if (it->next == nullptr)
    {
        free(it);
        return;
    }
    it->front->next = it->next;
    free(it);
    return;
}
void del_max()
{
    int MAX = 0;
    node *Max_id;
    for (node *it = head; it != nullptr; it = it->next)
    {
        if (it->val > MAX)
        {
            MAX = it->val;
            Max_id = it;
        }
    }
    del(Max_id);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (re int i = 1; i <= n; ++i)
    {
        int tmp;
        cin >> tmp;
        add(tmp);
    }

    output();
    return 0;
}