/*
Time complexity : O(N)
Space complexity : O(1)
Best approach is : recursively look for the node with no grandchildren and also both it's left and right child in the left sub-tree.
                    Then store node->right in temp and make node->right=node->left.
                    Insert temp in first node NULL on right of node by node=node->right. Repeat until it is converted to linked list.
*/
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(root == NULL or (!root->left and !root->right) ) return ;
        
        
        if(root->left != NULL )
        {
            flatten(root->left);
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            
            TreeNode* t = root->right;
            while(t->right != NULL)
             t = t->right;
            
            t->right = temp;
            
        }
        
        flatten(root->right);
        
    }
  
};
