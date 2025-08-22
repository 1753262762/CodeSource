#include <bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    node *next;
    node() { value = 0, next = NULL; }
};
int main()
{
    node *head;
    head = new (node);
    head->value = 1;
    head->next = new (node);
    cout << head->value << ' ' << head->next << endl;
    head->next->value = 2;
    head->next->next = new (node);
    cout << head->next->value << ' ' << head->next->next << endl;
    head->next->next->value = 3;
    cout << head->next->next->value << ' ' << head->next->next->next << endl;
    for (node *it = head; it != NULL; it = it->next)
    {
        cout << it->value << ' ';
    }
    cout << endl;
    head->next = head->next->next;
    free(head->next->next);
    for (node *it = head; it != NULL; it = it->next)
    {
        cout << it->value << ' ';
    }
    cout << endl;
    return 0;
}