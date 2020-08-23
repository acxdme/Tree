//insertion in a tree level order wise
/*
Time complexity : O(N)  , at worst each node is traversed once.
Space complexity : O(n) , for queue.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) //i have declared a function inside struct.
    {
        val = x;
        left = right = NULL;
    }
};

void insert(TreeNode *node, int data)
{
    queue<TreeNode *> q; //Using BFS to find the next empty place.
    q.push(node);

    while (!q.empty())
    {
        TreeNode *p = q.front();
        q.pop();
        if (p->left == NULL)
        {
            p->left = new TreeNode(data);
            break;
        }
        else
        {
            q.push(p->left);
        }
        if (p->right == NULL)
        {
            p->right = new TreeNode(data);
            break;
        }
        else
        {
            q.push(p->right);
        }
    }
}

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(10);
    insert(root, 13);
    insert(root, 3);
    insert(root, 75);
    insert(root, 83);
    insert(root, 92);
    inorder(root);

    return 0;
}
