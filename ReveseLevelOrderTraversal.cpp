/*
Time complexity : O(n) , each node is visited once
Space complexity : O(n), the extra space of O(N) for queue and O(N) for stack.
Algo  :      Use the BFS using queue to get the nodes at a particular level and push these nodes in stack. Then pop all elements the stack to get the reverse 
             level order.( while inserting elements in queue insert the right node then left node).

Note: In the leetcode version of this question we have to return vector<vector<int>> answer so instead of stack store all level order nodes in a vector v and then push v 
in result and finally return the answer after reversing it.
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

void reverseBFS(TreeNode* root)
{
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* p= q.front();
        q.pop();
        s.push(p);
        if(p->right) q.push(p->right);
        if(p->left)  q.push(p->left);
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}


int main()
{
    TreeNode* root = new TreeNode(1);

     root->left =new TreeNode(10);
     root->right =new TreeNode(20);

     root->left->left = new TreeNode(30);
     root->left->right = new TreeNode(40);
     root->right->left = new TreeNode(50);
    //  root->right->right = new TreeNode(60);

     reverseBFS(root);

}
