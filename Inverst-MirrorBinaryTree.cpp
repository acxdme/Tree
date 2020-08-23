/*
Time complexity : O(N)
Space complexity : O(h) , h is the height of the tree.
 Algo : Do post order traversal using recursion
          if root is null return
           swap root's left with root's right.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;
   TreeNode *left,*right;
   TreeNode(int x)
   {
       data=x;
       left=right=NULL;
   }
};

void levelorder(TreeNode* root)
{
    if(root==NULL)
      return ;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* p= q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);

    }
}
void invertTree(TreeNode* root)
{
    if(root==NULL)
    return ;
    invertTree(root->left);
    invertTree(root->right);
    
    TreeNode* temp= root->left;
    root->left=root->right;
    root->right=temp;
}

int main()
{
    TreeNode* root= new TreeNode(10);
    root->left= new TreeNode(20);
    root->right= new TreeNode(30);
    root->left->left= new TreeNode(40);
    root->left->right= new TreeNode(50);
    root->right->left= new TreeNode(60);
    root->right->right= new TreeNode(70);

    levelorder(root);
    cout<<endl;
    invertTree(root); //inverting the tree aka getting it's mirror image
    cout<<"The inverted tree is"<<endl;
    levelorder(root);
    cout<<endl;

    return 0;

}

