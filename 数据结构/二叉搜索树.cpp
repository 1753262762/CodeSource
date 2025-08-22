#include <bits/stdc++.h>
using namespace std;

#define re register

struct node
{
    int key;
    node *left, *right;
    int size, cnt;
    node() : left(nullptr), right(nullptr), size(1), cnt(1) {}
};
void dfs(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    dfs(root->left);
    cout << root->key << endl;
    dfs(root->right);
    return;
}
int find_max(node *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->key;
}
int find_min(node *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->key;
}
bool search_value(node *root, int x)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (x == root->key)
    {
        return 1;
    }
    else if (x > root->key)
    {
        if (root->right == nullptr)
            return 0;
        return search_value(root->right, x);
    }
    else //(x < root->key)
    {
        if (root->left == nullptr)
            return 0;
        return search_value(root->left, x);
    }
}
void insert_node(node *&root, int x)
{
    if (root == nullptr)
    {
        root = new node;
        root->key = x;
        return;
    }
    if (x > root->key)
    {
        ++(root->size);
        insert_node(root->right, x);
    }
    else if (x < root->key)
    {
        ++(root->size);
        insert_node(root->left, x);
    }
    else if (x == root->key)
    {
        ++(root->cnt);
        ++(root->size);
    }
}
void del_node(node *&root, int x)
{
    if (root == nullptr)
    {
        cout << "Not found! Can't delete" << endl;
        return;
    }
    if (x > root->key)
    {
        del_node(root->right, x);
    }
    else if (x < root->key)
    {
        del_node(root->left, x);
    }
    else
    {
        if (root->cnt > 1)
        {
            --(root->cnt);
            return;
        }
        if (root->left == nullptr and root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->right == nullptr)
        {
            node *tmp = root;
            root = root->left;
            delete tmp;
        }
        else if (root->left == nullptr)
        {
            node *tmp = root;
            root = root->right;
            delete tmp;
        }
        else
        {
            // 右子树最小值替换
            node *tmp = root->right;
            while (tmp->left != nullptr)
            {
                tmp = tmp->left;
            }
            root->key = tmp->key;
            del_node(root->right, tmp->key);
        }
        if (root != nullptr)
        {
            root->size = (root->left != nullptr ? root->left->size : 0) + (root->right != nullptr ? root->right->size : 0) + root->cnt; // 更新 size
        }
    }
} // size操作未实现

int query_Rank(node *root, int x)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (x < root->key)
    {
        return query_Rank(root->left, x);
    }
    if (x == root->key)
    {
        return (root->left != nullptr ? root->left->size : 0) + 1;
    }
    return query_Rank(root->right, x) + (root->left != nullptr ? root->left->size : 0) + root->cnt;
}
int query_Rank_k_value(node *root, int x)
{
    if (root == nullptr)
    {
        return -1;
    }
    int leftSize = (root->left != nullptr) ? root->left->size : 0;
    if (x <= leftSize)
    {
        return query_Rank_k_value(root->left, x);
    }
    else if (x == leftSize + 1)
    {
        return root->key;
    }
    else
    {
        return query_Rank_k_value(root->right, x - leftSize - 1);
    }
}
int main()
{
    freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    node *Tree = nullptr;
    for (re int i = 1; i <= n; ++i)
    {
        int tmp;
        cin >> tmp;
        insert_node(Tree, tmp);
    }
    return 0;
}