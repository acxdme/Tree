/*
Time complexity : O(N), Each node is visited once.
Space complexity : O(N) , space used for queue.
My approach : Use a queue (BFS) to get the level order elements and stack to push the nodes and getting the reverse level order traversal.
*/
//This is the reverse level order traversal, if the output has to be
// given level wise then store each level as vector than push it in stack then finally pop the vector
//and print its elements.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void reverseBFS(TreeNode *root)
{
    queue<TreeNode *> q;
    stack<TreeNode *> s;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *p = q.front();
        q.pop();
        s.push(p);
        if (p->right)
            q.push(p->right);
        if (p->left)
            q.push(p->left);
    }
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(10);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(50);
    //  root->right->right = new TreeNode(60);

    reverseBFS(root);
}
