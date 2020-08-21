/*
Time complexity : O(n)    (Time taken to traverse the binary Tree)
Space complexity : O(n)   (size of the queue)
Algo : (To delete any node in a binary Tree , swap that node's  value with the deepest rightmost node.)
        Perform a BFS and find out the target node which is to be deleted and also save the deepest rightmost node let's call it lastone.
        Perform another BFS whose pupose will be to delete the target node.
        Change the value of the target to the value of lastone.
Note : Deletion in BST is a completely different process.
*/
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

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void deleteDeepest(TreeNode *root, TreeNode *temp)
{
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p == temp)
        {
            p = NULL;
            delete (temp);
            return;
        }

        if (p->right)
        {
            if (p->right == temp)
            {
                p->right = NULL;
                delete (temp);
                return;
            }
            else
                q.push(p->right);
        }
        if (p->left)
        {
            if (p->left == temp)
            {

                p->left = NULL;
                delete (temp);
                return;
            }
            else
                q.push(p->left);
        }
    }
}

TreeNode *deleteit(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL and root->right == NULL)
    {
        if (root->data == val)
            return NULL;
        else
            return root;
    }
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *temp;
    TreeNode *key_node = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->data == val)
            key_node = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != NULL)
    {
        int y = temp->data;
        deleteDeepest(root, temp);
        key_node->data = y;
    }

    return root;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(45);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(23);
    root->left->right = new TreeNode(87);
    root->right->left = new TreeNode(43);
    root->right->right = new TreeNode(30);

    inorder(root); // before deletion
    cout << endl;
    cout << "Enter the node's value to be deleted" << endl;
    int val;
    cin >> val;
    root = deleteit(root, val);

    inorder(root);

    return 0;
}
