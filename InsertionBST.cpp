/*
Time complexity : O(h) where h is the height of the tree.
Space complexity : O(n) , for using the call stack
Algo :       Traverse the BST using its unique value, (value of left node< rootnode <value of right node)
              Check if the left/right node is present 
                          if node is absent insert the new node with given data
                          else recursively call the left/right node.
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
void insertBST(TreeNode *root, int data)
{
    if (root == NULL)
        return;
    if(data > root->data)
    {
        if(root->right)
         insertBST(root->right,  data);
        else
        {
            root->right = new TreeNode( data);
            return;
        }
    }
    else
    {
        if(root->left)
         insertBST(root->left, data);
        else
        {
            root->left =new TreeNode(data);
            return;
        }
        
    }
    
}
int main()
{
    TreeNode *root = new TreeNode(50);

    root->left = new TreeNode(25);
    root->right = new TreeNode(60);

    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(30);
    root->right->left = new TreeNode(58);
    root->right->right = new TreeNode(70);

    inorder(root);
    cout << endl;

    insertBST(root, 25);
    insertBST(root,61);
    insertBST(root,67);

    inorder(root);
    cout << endl;

    return 0;
}
               
              
