#include <bits/stdc++.h>
using namespace std;

#define re register

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *front, *back;
    };

    Node *head;

public:
    LinkedList()``: head(nullptr) {}

    // 插入到最后一位
    void InsertNode(int data)
    {
        if (head == nullptr)
        {
            head = new Node{data, nullptr, nullptr};
            return;
        }
        Node *it = head;
        while (it->back != nullptr)
        {
            it = it->back;
        }
        it->back = new Node{data, it, nullptr};
    }

    // 插入到第x位后
    void InsertNode(int position, int data)
    {
        if (FindNode(position) == -1)
        {
            return;
        }
        Node *it = head;
        for (re int i = 1; i < position; ++i)
        {
            it = it->back;
        }
        Node *newNode = new Node{data, it, it->back};
        if (it->back != nullptr)
        {
            it->back->front = newNode;
        }
        it->back = newNode;
    }

    // 查询x位
    int FindNode(int position)
    {
        Node *it = head;
        for (re int i = 1; i < position; ++i)
        {
            if (it == nullptr)
            {
                cout << "Error!!" << endl;
                return -1;
            }
            it = it->back;
        }
        return it ? it->data : -1;
    }

    // 删除第x位
    void DeleteNode(int position)
    {
        if (FindNode(position) == -1)
        {
            return;
        }
        Node *it = head;
        for (re int i = 1; i < position; ++i)
        {
            it = it->back;
        }
        if (it->front)
        {
            it->front->back = it->back;
        }
        else
        {
            head = it->back; // 删除头节点
        }
        if (it->back)
        {
            it->back->front = it->front;
        }
        delete it;
    }

    // 打印整个列表
    void PrintList()
    {
        Node *it = head;
        while (it != nullptr)
        {
            cout << it->data << ' ';
            it = it->back;
        }
        cout << endl;
    }

    // 析构函数,释放链表内存
    ~LinkedList()
    {
        while (head)
        {
            DeleteNode(1);
        }
    }
};

int main()
{
    LinkedList list; // 创建链表对象
    list.InsertNode(1);
    list.InsertNode(2);
    list.InsertNode(3);
    list.InsertNode(4);
    list.InsertNode(5);
    list.DeleteNode(3);
    list.InsertNode(2, 5454);
    list.FindNode(3);
    list.InsertNode(4, 54545);
    list.DeleteNode(2);
    list.PrintList();
    return 0;
}
