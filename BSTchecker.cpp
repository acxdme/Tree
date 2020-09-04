/*

 #A binary tree is a valid BST when the left subtree is lesser in value to the node and the right subtree is greater in value to the node.
 The simple method which checks that the right child is smaller than root and left child is larger than root is wrong since ,we have to check the whole subtee and not just it's
 immediate children.
 
 #The method where we compare  the min and max  values (updated with respect to whole tree) with the nodes is efficient and good but the range of min and max can create problems.
 
 # Instead of taking max and min if we take the left and right (TreeNode* ) and compare their values with the corresponding nodes recursively, we obtain the solution for
 the leetcode problem and this method is efficient (O(N) time complexity ).Initially left and right are null but their values change as we traverse the tree.
 
 #So the next method is to make an In-order traversal of the tree and store the oreder in an array ,  the array must be in ascending order for a tree to be BST , but this
 method takes takes O(N) space for the array.
 
 # The last method is to make an In-oreder traversal but this time just compare the value with the previous value so the need to store the complete order in an array is not 
 required.
 
*/

// using the left ,right node method. (question from : GFG)
class Solution {
public:
    bool is_helper(TreeNode* root, TreeNode* l, TreeNode* r)
    {
        if (root==NULL)
            return true;
        if(l!=NULL and l->val >= root->val)
            return false;
        if(r!=NULL and r->val <= root->val)
            return false;
            
         return ( is_helper(root->left,l,root) and is_helper(root->right,root,r) ); 
    }
    
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL or (root->left==NULL and root->right == NULL))
            return true;
        return is_helper(root,NULL,NULL);
        
    }
};
