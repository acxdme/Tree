/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Method-1  using dfs to calculate The maximum depth , which is the number of nodes along the longest path from the root node down to the farthest leaf node.
/*
Time complexity : O(n) tree can be screw
Space complexity : O(n)
*/
class Solution 
{
private:
    int helper(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return  1+ max(helper(root->left),helper(root->right));
    }
public:
    int maxDepth(TreeNode* root) 
    {
        return helper(root);  
    }
};

//Method-2 Using bfs to calculate the
class Solution{
    
public :
int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++ res;

        int n=  q.size();
        for(int i = 0 ; i < n; ++ i)
        {
            
            TreeNode *p = q.front();
            q.pop();
            
            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);

        }
    }
    
    return res;
}
};
