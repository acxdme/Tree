/*
Time complexity : O(n)
Space complexity : O(h) where h can be logn or n.
*/

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;   // if return -1 is used than it will give you the number of edges (in longest path from root to node)which is the actual defination.
                    //return 0 will give you the nodes in heigt path.
    return max(height(root->left) , height(root->right)) + 1;
}
