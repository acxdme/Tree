/*
Iterative approach 
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

void recursiveInorder(TreeNode* root)
{
   stack<TreeNode*> s;
   TreeNode* curr=root;
   while(curr!=NULL or s.empty()==false)
   {
       while(curr!=NULL)
       {
           s.push(curr);
           curr=curr->left;  
       }

       curr=s.top();
       s.pop();
       cout<<curr->data<<" ";

       curr=curr->right;
   }
}

int main()
{
    TreeNode* root= new TreeNode(10);
     root->left =new TreeNode(5);
     root->right =new TreeNode(15);
     root->left->right = new TreeNode(23);
     root->left->left = new TreeNode(83);
     recursiveInorder(root);

     return 0;
}
/*
recursive approach
*/

void recursiveInorder(TreeNode* root)
{
  if(root==NULL)
     return;
    recursiveInorder(root->left);
    cout<<root->data<<" ";
    recursiveInorder(root->right);
}
