/*
 The problem is to find and print all the paths from root to leaf.
 Time complexity : O(N)
 Space complexity : O(N)


Your code obviously collects and returns all paths from the root to the leaf nodes.
It does so by using DFS. Every node is visited during the algorithm execution, and none of them is visited more than once.
However, you have to either print or store the path when you find it. In your program, you create new ArrayList and store it in variable rst.
Number of paths equals the number of leaf nodes l, and the path length equals the height of the tree h, so the total complexity is O(n + hl).
Values of l and h are not independent, so let us examine two interesting cases.
In case of balanced binary tree, there are n/2 leaf nodes on average, and height is log2(n), which gives O(nlogn).
On the other hand, when tree degenerates in the linked list, there is only one leaf and the length of that path is n, so the complexity for this case is O(n).
 */
 
 #include<bits/stdc++.h>
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
void get_paths(vector<int> paths, TreeNode* root)
{
 
    if(root==NULL)
    {
        return;
    }

    paths.push_back(root->data);

    if(root->left ==NULL and root->right == NULL)
    {
         for(int i=0;i<paths.size();i++)
         cout<<paths[i]<<" ";
          cout<<endl;
    }
            
     get_paths(paths,root->left);
     get_paths(paths,root->right);
 
}

int main()
{
    TreeNode *root = new TreeNode(50);

    root->left = new TreeNode(20);
    root->right = new TreeNode(60);

    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(25);
    root->right->left = new TreeNode(55);
    root->right->right = new TreeNode(70);

    root->left->left->right = new TreeNode(12);
    root->right->left->right = new TreeNode(58);

    vector<int> paths;
    get_paths(paths,root);
    return 0;
}
 
