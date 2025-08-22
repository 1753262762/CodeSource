#include <bits/stdc++.h>
using namespace std;

#define re register

struct node
{
    int data;
    node *front, *back;
} *head;
void InsertNode(int position, int data); // 插入到第x位后
void InsertNode(int data);               // 插入到最后一位
int FindNode(int position);              // 查询x位
void PrintList();                        // 打印整个列表
void DeleteNode(int position);           // 删除第x位
int main()
{
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    DeleteNode(3);
    Insert(2, 5454);
    FindNode(3);
    Insert(4, 54545);
    DeleteNode(2);
    PrintList();
    return 0;
}
int FindNode(int position)
{
    node *it = head;
    for (re int i = 1; i < position; ++i)
    {
        if (it->back == NULL)
        {
            cout << "error!!" << endl;
            return -1;
        }
        it = it->back;
    }
    return it->data;
}
void Insert(int data)
{
    if (head == NULL)
    {
        head = new node;
        head->data = data;
        head->back = NULL;
        head->front = NULL;
        return;
    }
    node *it = head;
    while (it->back != NULL)
    {
        it = it->back;
    }
    it->back = new node;
    it->back->data = data;
    it->back->front = it;
    it->back->back = NULL;
    return;
}
void Insert(int position, int data)
{
    if (FindNode(position) == -1)
    {
        return;
    }
    node *it = head;
    for (re int i = 1; i < position; ++i)
    {
        it = it->back;
    }
    if (it->back == NULL)
    {
        it->back = new node;
        it->back->data = data;
        it->back->back = NULL;
        it->back->front = it;
        return;
    }
    node *to = it->back;
    node *New = new node;
    New->data = data;
    New->front = it;
    New->back = to;
    it->back = New;
    to->front = New;
    return;
}
void DeleteNode(int position)
{
    if (FindNode(position) == -1)
    {
        return;
    }
    node *it = head;
    for (re int i = 1; i < position; ++i)
    {
        it = it->back;
    }
    it->front->back = it->back;
    free(it);
}
void PrintList()
{
    node *it = head;
    while (it->back != NULL)
    {
        cout << it->data << ' ';
        it = it->back;
    }
    cout << it->data << endl;
    return;
}